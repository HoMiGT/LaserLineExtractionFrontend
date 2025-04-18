#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <filesystem>
#include <QMessageBox>
#include "cnlhelper.h"
#include <QDateTime>
#include "util.h"
#include <QObject>
#include <QDir>
#include <QTimer>
#include <QVector>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "taskdailog.h"
#include <QProcess>
#include <QJsonDocument>
#include <cpr/cpr.h>
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <format>
#include "NavLogger.h"

namespace fs = std::filesystem;


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent)
	, m_ui(new Ui::MainWindow)
	, m_uiSetting(nullptr)
{
	m_ui->setupUi(this);

	baseSettingJson(m_jsonObj); // 初始化配置
	m_cpuCount = m_jsonObj->value("parallel_count").toInt();

	m_uiSetting = new SettingWindow(this);  // 初始化配置界面指针
	connect(m_uiSetting, &SettingWindow::updateSetting, this, &MainWindow::updateSetting);

	m_ui->action_addTask->setIcon(QIcon(":/Icon/add_task.svg"));
	m_ui->action_clearList->setIcon(QIcon(":/Icon/clear_task.svg"));
	m_ui->action_startTask->setIcon(QIcon(":/Icon/start_no.svg"));

	m_ui->tableView_taskList->setShowGrid(true);  // 初始化tableview控件
	m_ui->tableView_taskList->setGridStyle(Qt::DotLine);
	m_ui->tableView_taskList->setSortingEnabled(true);
	m_taskModel = new QStandardItemModel();
	QStringList labels = QObject::tr("任务名称,任务状态").simplified().split(",");
	m_taskModel->setHorizontalHeaderLabels(labels);
	m_ui->tableView_taskList->setModel(m_taskModel);
	m_ui->tableView_taskList->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_ui->tableView_taskList->setSelectionMode(QAbstractItemView::SingleSelection);
	m_ui->tableView_taskList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_ui->tableView_taskList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	m_ui->lcdNumber_success->setFixedWidth(m_ui->lcdNumber_success->sizeHint().width()); // 调整lcdnumber显示
	m_ui->lcdNumber_fail->setFixedWidth(m_ui->lcdNumber_fail->sizeHint().width());
	m_ui->lcdNumber_checkSumCount->setFixedWidth(m_ui->lcdNumber_checkSumCount->sizeHint().width());

	m_taskTimer = new QTimer(this); // 初始化更新状态定时器
	connect(m_taskTimer, &QTimer::timeout, this, &MainWindow::updateTaskState);
	m_taskTimer->start(1500);

	if (m_cpuCount == 0) { m_cpuCount = QThread::idealThreadCount(); } // 启动对应核数的线程池

	m_threadPool.setMaxThreadCount(m_cpuCount);

	connect(this, &MainWindow::runTaskSignal, this, &MainWindow::startRunTask); // 开始运行任务的信号与槽函数

}

MainWindow::~MainWindow()
{
	delete m_taskTimer;
	delete m_taskModel;
	delete m_uiSetting;
	delete m_ui;
}

// 退出trigger
void MainWindow::on_action_exit_triggered()
{
	close();
}

// 配置trigger
void MainWindow::on_action_setting_triggered()
{
	m_uiSetting->show();
}

// 打开文件夹
inline void open_directory(const QString& text) {
	const fs::path path = text.toStdString();
	if (!fs::exists(path)) {
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Icon::Critical);
		msgBox.setText(QString("文件路径:\"") + text + QString("\"，不存在，请核对后，手动打开文件夹路径！"));
		msgBox.show();
		return;
	}
	QDesktopServices::openUrl(QUrl(QString("file:") + text, QUrl::TolerantMode));
}

// 提取
void MainWindow::on_pushButton_extractImagePath_clicked()
{
	const QString text = m_ui->pushButton_extractImagePath->text();
	if (text.isEmpty()) { return; }
	open_directory(text);
}


void MainWindow::on_pushButton_seedPath_clicked()
{
	const QString text = m_ui->pushButton_seedPath->text();
	if (text.isEmpty()) { return; }
	open_directory(text);
}


void MainWindow::on_pushButton_failedImagePath_clicked()
{
	const QString text = m_ui->pushButton_failedImagePath->text();
	if (text.isEmpty()) { return; }
	open_directory(text);
}


void MainWindow::on_action_addTask_triggered()
{
	auto task_dailog = new TaskDailog(this);
	connect(task_dailog, &TaskDailog::addTask, this, &MainWindow::dailogAddTask);  // 关联信号与槽函数
	task_dailog->exec();
}

void MainWindow::dailogAddTask(QPair<QString, QString> msg)
{
	auto timestamp = QDateTime::currentDateTime().toString("yyMMddhhmmss");
	auto setting_name_py = CNLHelper::Instance()->CNToPY(msg.first).replace(" ", "");

	auto taskName = msg.first + "_" + timestamp;
	auto taskNamePy = setting_name_py + "_" + timestamp;
	auto extractImagePath = msg.second;

	auto datestamp = QDateTime::currentDateTime().toString("yyyyMMdd");

	auto savedSeedPath = m_jsonObj->value("upload_save_path").toString() + "/" + datestamp + "/" + taskNamePy;  // 保存种子路径
	auto failedImagePath = m_jsonObj->value("failed_image_path").toString() + "/" + datestamp + "/" + taskNamePy; // 保存失败图片路径
	auto isDingNotic = m_jsonObj->value("is_ding_notice").toBool();  // 是否钉钉通知
	auto dingDingUrl = m_jsonObj->value("ding_ding_url").toString();  // 钉钉通知url
	auto isUploadServer = m_jsonObj->value("is_upload_server").toBool(); // 是否上传服务器
	auto pythonExePath = m_jsonObj->value("python_exe_path").toString();  // python解释器的执行路径
	auto pythonScriptPath = m_jsonObj->value("python_script_path").toString();  // python执行脚本
	QFileInfo pyScriptFileInfo(pythonScriptPath);
	QDir pyScriptDir(pyScriptFileInfo.absolutePath());
	std::stringstream ss;
	ss << pythonExePath.toStdString();
	ss << " ";
	ss << pyScriptDir.absolutePath().toStdString();
	ss << "/count_num.py";
	ss << " -config ";
	auto pythonStaticScriptPath = QString::fromStdString(ss.str());

	QDir dir;
	if (!dir.exists(savedSeedPath)) { dir.mkpath(savedSeedPath); }
	if (!dir.exists(failedImagePath)) { dir.mkpath(failedImagePath); }

	fs::path customeConfig = fs::current_path();
	customeConfig.append("settings");
	customeConfig.append(msg.first.toStdString() + ".json");

	auto customeJsonObj = readJsonFile(customeConfig).value();
	auto extractHeight = customeJsonObj.value("extract_height").toDouble(); // 提取高
	double extractWidth = customeJsonObj.value("extract_width").toDouble(); // 提取宽
	double extractX = customeJsonObj.value("extract_x").toDouble(); // 提取x
	double extractY = customeJsonObj.value("extract_y").toDouble(); // 提取y
	int qrSideLength = customeJsonObj.value("extract_sideLength").toInt(); // 二维码边长
	double labelWidth = customeJsonObj.value("label_width").toDouble(); // 标签宽
	double labelHeight = customeJsonObj.value("label_height").toDouble(); // 标签高
	int block_num = 10;
	if (customeJsonObj.contains("block_number")) {
		block_num = customeJsonObj.value("block_number").toInt();
	}
	auto ti = std::make_shared<TaskInfo>();
	ti->configName = msg.first;
	ti->taskName = taskName;
	ti->extractImagePath = extractImagePath;
	ti->savedSeedPath = savedSeedPath;
	ti->failedImagePath = failedImagePath;
	ti->status = TaskState::WAIT;
	ti->extractSuccessCount = 0;
	ti->extractFailedCount = 0;
	ti->successRatio = static_cast<double>(ti->extractSuccessCount) / static_cast<double>(ti->extractFailedCount + 1e-4);
	ti->isDingNotic = isDingNotic;
	ti->dingDingUrl = dingDingUrl;
	ti->isUploadServer = isUploadServer;
	ti->pythonExePath = pythonExePath;
	ti->pythonScriptPath = pythonScriptPath;
	ti->extractHeight = extractHeight;
	ti->extractWidth = extractWidth;
	ti->extractX = extractX;
	ti->extractY = extractY;
	ti->qrSideLength = qrSideLength;
	ti->labelWidth = labelWidth;
	ti->labelHeight = labelHeight;
	ti->blockNum = block_num;
	ti->extractCheckCount = 0;
	ti->pythonStatisticsPath = pythonStaticScriptPath;

	m_taskMap.insert(msg.first + "_" + timestamp, ti);

	m_taskModel->setItem(m_taskModelIndex, 0, new QStandardItem(taskName));
	m_taskModel->setItem(m_taskModelIndex, 1, new QStandardItem("等待"));

	if (m_taskModelIndex == 0) {
		m_ui->action_startTask->setIcon(QIcon(":/Icon/starting.svg"));
		m_startActionState = StartActionColor::GREEN;
	}
	m_taskModelIndex++;

}

void MainWindow::updateSetting()
{
	m_jsonObj = nullptr;
	baseSettingJson(m_jsonObj);
}

// 更新任务状态
void MainWindow::updateTaskState()
{
	if (m_taskMap.empty()) { return; }  // 没有任务
	if (m_currentTaskName.isEmpty()) { return; }  // 没有正在运行的任务

	std::shared_ptr<TaskInfo> updateInfo = m_taskMap[m_currentTaskName]; // 获取当前正在执行任务的信息
	if (updateInfo == nullptr) {
		return;
	}

	auto success_count = getDirCount(updateInfo->savedSeedPath);
	auto fail_count = getDirCount(updateInfo->failedImagePath);
	double ratio = 0;
	if (success_count == 0) {
		ratio = 0;
	}
	else if (success_count != 0 && fail_count == 0) {
		ratio = 1;
	}
	else {
		ratio = static_cast<double>(success_count) / static_cast<double>(fail_count + success_count);
	}
	updateInfo->extractSuccessCount = success_count;
	updateInfo->extractFailedCount = fail_count;
	updateInfo->successRatio = ratio * 100;
	m_ui->lcdNumber_success->display(updateInfo->extractSuccessCount);
	m_ui->lcdNumber_fail->display(updateInfo->extractFailedCount);
	m_ui->progressBar_successRatio->setValue(static_cast<int>(updateInfo->successRatio));
	m_ui->lcdNumber_checkSumCount->display(updateInfo->extractCheckCount);

	int spend_time = 0;
	if (updateInfo->endTime.isNull()) {
		spend_time = updateInfo->startTime.secsTo(QTime::currentTime());
	}
	else {
		spend_time = updateInfo->startTime.secsTo(updateInfo->endTime);
	}
	auto spend_hour = spend_time / 3600;
	auto spend_minues = (spend_time % 3600) / 60;
	auto spend_seconds = (spend_time % 3600) % 60;


	m_ui->lineEdit_taskName->setText(updateInfo->taskName);
	m_ui->pushButton_extractImagePath->setText(updateInfo->extractImagePath);
	m_ui->pushButton_seedPath->setText(updateInfo->savedSeedPath);
	m_ui->pushButton_failedImagePath->setText(updateInfo->failedImagePath);
	m_ui->lineEdit_spendTime->setText(QString::number(spend_hour) + ":" + QString::number(spend_minues) + ":" + QString::number(spend_seconds));
}

void MainWindow::taskFininshed()
{
	if (m_startActionState == StartActionColor::RED) {
		// 修改action状态 -> 绿色
		m_ui->action_startTask->setIcon(QIcon(":/Icon/starting.svg"));
		m_startActionState = StartActionColor::GREEN;
	}
}

void MainWindow::updateLabelCount(QString taskName, int count) {
	m_taskMap[taskName]->extractCheckCount = count;
}

// 并发执行任务
bool MainWindow::multiRunTask(std::shared_ptr<TaskInfo>& task_info)
{
	try {
		// 1. 将提取路径下得图片 存入到 QStringList中
		QStringList files;
		auto extractPath = fs::path(task_info->extractImagePath.toStdString());
		getExtractImageName(files, extractPath, task_info->taskName, m_cpuCount);
		// 2. 根据核数将任务拆分
		// 3. 多线程处理 调用QProcess来执行脚本
		for (auto& img_file : files) {
			if (img_file.isEmpty()) { continue; }

			QJsonObject info;
			info["config_name"] = task_info->configName;
			info["extract_path"] = task_info->extractImagePath;
			info["save_seed_path"] = task_info->savedSeedPath;
			info["failed_image_path"] = task_info->failedImagePath;
			info["image_names"] = img_file;
			info["extract_width"] = task_info->extractWidth;
			info["extract_height"] = task_info->extractHeight;
			info["extract_x"] = task_info->extractX;
			info["extract_y"] = task_info->extractY;
			info["qr_side_length"] = task_info->qrSideLength;
			info["label_width"] = task_info->labelWidth;
			info["label_height"] = task_info->labelHeight;
			info["block_number"] = task_info->blockNum;


			std::unique_ptr<QJsonObject> info_ptr = std::make_unique<QJsonObject>(info);
			ExcutePythonScript* task = new ExcutePythonScript(task_info->pythonExePath, task_info->pythonScriptPath, std::move(info_ptr));
			m_threadPool.start(task); // 添加任务到线程池
		}
		// 4. 调用python脚本并获取输出
		std::stringstream ss;
		ss << task_info->pythonStatisticsPath.toStdString();
		ss << "\"{\\\"extract_path\\\": \\\"";
		ss << task_info->extractImagePath.toStdString();
		ss << "\\\"}\"";
		auto py_script = ss.str();
		auto pySender = std::make_unique<PythonGetLabelCountSender>();
		connect(pySender.get(), &PythonGetLabelCountSender::labelCount, this, &MainWindow::updateLabelCount);
		auto pyTask = new PythonGetLabelCount(task_info->taskName, py_script, std::move(pySender));
		m_threadPool.start(pyTask);
		// 4. 等待所有任务完成，更新状态，以及完成文件夹名修改
		m_threadPool.waitForDone(); // 等待所有任务完成

		for (auto& img_file : files) {
			QFile file(img_file);
			if (file.exists()) {
				file.remove();
			}
		}
		return true;
	}
	catch (std::exception& e) {
		qWarning() << "并发执行任务出现错误:" << e.what();
		return false;
	}
}

void MainWindow::updateTableViewState(QString& targetKey, TaskState& state)
{
	// 遍历所有行
	for (int i = 0; i < m_ui->tableView_taskList->model()->rowCount(); ++i) {
		QModelIndex index = m_ui->tableView_taskList->model()->index(i, 0); // 获取第0列的索引，假设这是key列
		QVariant keyData = m_ui->tableView_taskList->model()->data(index); // 获取该行的key值
		if (keyData.toString() == targetKey) { // 如果该行的key值与目标key相等
			QModelIndex stateIndex = m_ui->tableView_taskList->model()->index(i, 1); // 获取第0列的索引，假设这是key列
			auto temp = getChinesByTaskState(state);
			m_ui->tableView_taskList->model()->setData(stateIndex, QVariant(temp));
			break; // 更新完后退出循环
		}
	}
	m_ui->tableView_taskList->viewport()->update();

}

// 任务列表双击事件
void MainWindow::on_tableView_taskList_doubleClicked(const QModelIndex& index)
{
	QString text = m_ui->tableView_taskList->model()->data(m_ui->tableView_taskList->model()->index(index.row(), 0)).toString();
	auto ti = m_taskMap[text];
	m_ui->lineEdit_taskName->setText(ti->taskName);
	m_ui->pushButton_extractImagePath->setText(ti->extractImagePath);
	m_ui->pushButton_seedPath->setText(ti->savedSeedPath);
	m_ui->pushButton_failedImagePath->setText(ti->failedImagePath);
	m_ui->lcdNumber_success->display(ti->extractSuccessCount);
	m_ui->lcdNumber_fail->display(ti->extractFailedCount);
	m_ui->progressBar_successRatio->setValue(ti->successRatio);
	m_ui->lcdNumber_checkSumCount->display(ti->extractCheckCount);
	int spend_time = 0;
	if (ti->startTime.isNull()) {
		m_ui->lineEdit_spendTime->setText("");
	}
	else {
		if (ti->endTime.isNull()) {
			spend_time = ti->startTime.secsTo(QTime::currentTime());
		}
		else {
			spend_time = ti->startTime.secsTo(ti->endTime);
		}
		auto spend_hour = spend_time / 3600;
		auto spend_minues = (spend_time % 3600) / 60;
		auto spend_seconds = (spend_time % 3600) % 60;
		m_ui->lineEdit_spendTime->setText(QString::number(spend_hour) + ":" + QString::number(spend_minues) + ":" + QString::number(spend_seconds));
	}


}

// 清理列表
void MainWindow::on_action_clearList_triggered()
{
	clear_folder();
	int runing_task_count = 0;
	QStringList remove_keys;
	for (auto it = m_taskMap.begin(); it != m_taskMap.end(); it++) {
		if (it.value()->status == TaskState::RUNING) {
			runing_task_count += 1;
			continue;
		}
		remove_keys.emplace_back(it.key());
	}

	for (auto& item : remove_keys) {
		m_taskMap.remove(item);
		if (item == m_ui->lineEdit_taskName->text()) {
			m_ui->lineEdit_taskName->clear();
			m_ui->pushButton_extractImagePath->setText("");
			m_ui->pushButton_seedPath->setText("");
			m_ui->pushButton_failedImagePath->setText("");
			m_ui->lcdNumber_success->display(0);
			m_ui->lcdNumber_fail->display(0);
			m_ui->progressBar_successRatio->setValue(0);
			m_ui->lineEdit_spendTime->setText("");
		}
	}


	int rows = m_ui->tableView_taskList->model()->rowCount();
	for (int r = rows - 1; r >= 0; r--)
	{
		auto cell_state = m_ui->tableView_taskList->model()->index(r, 1).data().toString();
		auto state = getTaskStateByChinese(cell_state);
		if (state == TaskState::RUNING) {
			continue;
		}
		m_taskModel->removeRow(r);
	}

	m_taskModelIndex = runing_task_count;

	for (auto it = m_taskMap.begin(); it != m_taskMap.end(); it++) {
		m_taskModel->setItem(m_taskModelIndex, 0, new QStandardItem(it.value()->taskName));
		m_taskModel->setItem(m_taskModelIndex, 1, new QStandardItem("等待"));
		m_taskModelIndex++;
	}

	if (m_taskModelIndex == 0) {
		m_ui->action_startTask->setIcon(QIcon(":/Icon/start_no.svg"));
		m_startActionState = StartActionColor::GRAY;
		m_currentTaskName.clear();
	}

}

// 开始任务
void MainWindow::on_action_startTask_triggered()
{
	if (m_taskMap.empty()) { return; }
	clear_folder();
	if (m_startActionState == StartActionColor::GREEN) {
		// 修改action状态 -> 红色
		m_ui->action_startTask->setIcon(QIcon(":/Icon/stop.svg"));
		m_startActionState = StartActionColor::RED;
		// 发送信号 ->执行任务
		emit runTaskSignal();
	}
	else if (m_startActionState == StartActionColor::RED) {
		// 修改action状态 -> 绿色
		m_ui->action_startTask->setIcon(QIcon(":/Icon/starting.svg"));
		m_startActionState = StartActionColor::GREEN;
	}
}

void MainWindow::startRunTask()
{

	MyTask* mt = new MyTask(*this);
	connect(mt, &MyTask::task_finished, this, &MainWindow::taskFininshed);
	mt->start();
}


ExcutePythonScript::ExcutePythonScript(QString& pythonExe, QString& pythonScript, std::unique_ptr<QJsonObject> info)
	:m_exe(pythonExe), m_script(pythonScript), m_info(std::move(info))
{

}

void ExcutePythonScript::run()
{
	QJsonObject jsonObj = *m_info.get();
	QJsonDocument jsonDoc(jsonObj);
	QByteArray jsonByteArray = jsonDoc.toJson(QJsonDocument::Compact);

	// 启动python脚本并传递参数
	QProcess process;
	QStringList args = { m_script,"-config",QString::fromUtf8(jsonByteArray) };
	logToFile(m_script + " -config " + QString::fromUtf8(jsonByteArray));
	process.start(m_exe, args);
	process.waitForFinished(-1);

	// 处理 Python 脚本返回的结果
	QByteArray output = process.readAllStandardOutput();
	QString outputString = QString::fromUtf8(output);
}

void MainWindow::on_action_help_triggered()
{
	QMessageBox::information(this, "帮助", "请联系开发人员");
}


MyTask::MyTask(MainWindow& mainwindow)
	:m_mainwindow{ &mainwindow }
{
}

void MyTask::run()
{
	for (auto task = m_mainwindow->m_taskMap.begin(); task != m_mainwindow->m_taskMap.end(); task++) {
		if (m_mainwindow->m_startActionState != StartActionColor::RED) { break; }
		// 1. 设置当前正在运行的任务
		m_mainwindow->m_currentTaskName = task.value()->taskName;
		// 2. 执行任务  阻塞 要么成功，要么失败
		auto task_info = m_mainwindow->m_taskMap[m_mainwindow->m_currentTaskName];
		task_info->status = TaskState::RUNING;
		m_mainwindow->updateTableViewState(task_info->taskName, task_info->status);
		task_info->startTime = QTime::currentTime();
		auto is_success = m_mainwindow->multiRunTask(task_info);
		task_info->endTime = QTime::currentTime();
		// 3. 判断任务执行成功与否 成功则判断是否上传服务器，是则需要修改文件夹名，不是则不需要修改，同理对于钉钉通知
		if (!is_success) { // 失败打印信息
			qWarning() << "`" << task_info->taskName << "`任务执行失败";
		}

		task_info->status = TaskState::SUCCESS;
		m_mainwindow->updateTableViewState(task_info->taskName, task_info->status);
		if (task_info->isUploadServer) { // 上传服务器，需要修改文件夹名
			auto finishedPaths = task_info->savedSeedPath.split("/");
			auto preFinishedPaths = finishedPaths.mid(0, finishedPaths.length() - 1);
			auto lastPath = finishedPaths.last();
			preFinishedPaths.append("finished_" + lastPath);
			auto newSavedSeedPath = preFinishedPaths.join("/");
			QDir dir;
			bool renameSuccess = dir.rename(task_info->savedSeedPath, newSavedSeedPath);
			if (!renameSuccess) {
				qWarning() << task_info->taskName << " 任务执行成功，但文件夹名重命名失败!";
			}
			else {
				task_info->savedSeedPath = newSavedSeedPath;
			}


			auto extractPaths = task_info->extractImagePath.split("/");
			auto preExtractPaths = extractPaths.mid(0, extractPaths.length() - 1);
			auto lastExtractPath = extractPaths.last();
			preExtractPaths.append("已提取_" + lastExtractPath);
			auto newExtractImagePath = preExtractPaths.join("/");
			QDir dirExtract;
			renameSuccess = dir.rename(task_info->extractImagePath, newExtractImagePath);
			if (!renameSuccess) {
				qWarning() << task_info->taskName << " 任务执行成功，但文件夹名重命名失败!";
			}
			else {
				task_info->extractImagePath = newExtractImagePath;
			}

		}
		if (task_info->isDingNotic) { // 钉钉通知，则需要发送通知内容
			// 创建请求体
			auto success_count = getDirCount(task_info->savedSeedPath);
			auto fail_count = getDirCount(task_info->failedImagePath);
			if (success_count != 0 || fail_count != 0) {
				double ratio = 0;
				if (success_count == 0) {
					ratio = 0;
				}
				else if (success_count != 0 && fail_count == 0) {
					ratio = 1;
				}
				else {
					ratio = static_cast<double>(success_count) / static_cast<double>(fail_count + success_count);
				}

				task_info->extractSuccessCount = success_count;
				task_info->extractFailedCount = fail_count;
				task_info->successRatio = ratio * 100;
			}

			auto label_kind = task_info->taskName.split("_").first();
			auto isUpload = task_info->isUploadServer ? QString::fromStdString("是") : QString::fromStdString("否");
			auto spend_time = task_info->startTime.secsTo(task_info->endTime);
			auto spend_hour = spend_time / 3600;
			auto spend_minues = (spend_time % 3600) / 60;
			auto spend_seconds = (spend_time % 3600) % 60;

			auto format_msg = QString::fromStdString("完成种子提取:\r\n标签种类: ") + label_kind +
				QString::fromStdString("\r\n图片路径: ") + task_info->extractImagePath +
				QString::fromStdString("\r\n标签路径: ") + task_info->savedSeedPath +
				QString::fromStdString("\r\n是否上传服务器: ") + isUpload +
				QString::fromStdString("\r\n提取成功标签数: ") + QString::number(task_info->extractSuccessCount) +
				QString::fromStdString("\r\n提取成功率: ") + QString::number(task_info->successRatio) +
				QString::fromStdString("% \r\n提取失败标签数: ") + QString::number(task_info->extractFailedCount) +
				QString::fromStdString("\r\n耗时: ") + QString::number(spend_hour) + ":" + QString::number(spend_minues) + ":" + QString::number(spend_seconds) +
				QString::fromStdString("\r\n提取检测数量: ") + QString::number(task_info->extractCheckCount);
			QString str_body;
			if (std::abs(task_info->extractCheckCount - task_info->extractSuccessCount) > 1000) {
				str_body = "{\"msgtype\":\"text\",\"text\":{\"content\":\"" + format_msg + "\"},\"at\":{\"atMobiles\":[\"15531096027\",\"19305819383\",\"13967133248\"],\"isAtAll\":false}}";
			}
			else {
				str_body = "{\"msgtype\":\"text\",\"text\":{\"content\":\"" + format_msg + "\"}}";
			}
			sendDingDingNotice(str_body, task_info->dingDingUrl);
		}
	}
	emit task_finished();
	QThread::msleep(1500);
	m_mainwindow->m_currentTaskName.clear();
}

void MyTask::sendDingDingNotice(QString& body, QString& url)
{
	cpr::Response r = cpr::Post(cpr::Url(url.toStdString()),
		cpr::Header{ {"Content-Type", "application/json"} },
		cpr::Body{ body.toStdString() });

	if (r.status_code == 200) {
		qDebug() << "Response: " << QString::fromStdString(r.text);
	}
	else {
		qDebug() << "Error: " << QString::number(r.status_code) << " - " << QString::fromStdString(r.error.message);
	}
}

PythonGetLabelCount::PythonGetLabelCount(const QString& taskName, const std::string& pyCommand,
	std::unique_ptr<PythonGetLabelCountSender> sender)
	:m_taskName(taskName), m_pyCommand(pyCommand), m_sender(std::move(sender))
{
}


void PythonGetLabelCount::run() {
	try {
		auto count = execute_python_script(m_pyCommand);
		m_sender->sendLabelCount(m_taskName, count);
	}
	catch (std::exception& e) {
		LOG_ERROR(std::format("Python统计标签理论个数错误: {}", e.what()));
	}
}

void PythonGetLabelCountSender::sendLabelCount(QString taskName, int count)
{
	emit labelCount(taskName, count);
}
