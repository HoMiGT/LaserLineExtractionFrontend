#pragma once

#include <QMainWindow>
#include "settingwindow.h"
#include <QPair>
#include <QString>
#include <QMap>
#include "model.h"
#include <QStandardItemModel>
#include <QThreadPool>
#include <QThread>
#include <QRunnable>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

private slots:
	void on_action_exit_triggered();

	void on_action_setting_triggered();

	void on_pushButton_extractImagePath_clicked();

	void on_pushButton_seedPath_clicked();

	void on_pushButton_failedImagePath_clicked();

	void on_action_addTask_triggered();

	void on_tableView_taskList_doubleClicked(const QModelIndex& index);

	void on_action_clearList_triggered();

	void on_action_startTask_triggered();

	void on_action_help_triggered();

	void startRunTask();

public slots:
	void dailogAddTask(QPair<QString, QString> msg);
	void updateSetting();
	void updateTaskState();
	void taskFininshed();

	void updateLabelCount(QString taskName, int count);

signals:
	void runTaskSignal();

public:
	QMap<QString, std::shared_ptr<TaskInfo>> m_taskMap;  // 任务字典 缓存任务对象
	StartActionColor m_startActionState; // 开始活动状态
	QString m_currentTaskName{ "" };  // 当前执行的任务的名称

public:
	void updateTableViewState(QString& targetKey, TaskState& state);
	bool multiRunTask(std::shared_ptr<TaskInfo>& task_info);

private:
	Ui::MainWindow* m_ui;
	SettingWindow* m_uiSetting;  // 配置窗体
	bool m_isbindingUpdateSetting{ false };// 是否绑定过update_setting slots 和 signals
	std::shared_ptr<QJsonObject> m_jsonObj;  // 共享公共配置的json对象
	QStandardItemModel* m_taskModel;  // tableview 的model
	int m_taskModelIndex{ 0 };  // 添加展示列表的最大索引
	QTimer* m_taskTimer;  // 定时任务更新
	int m_cpuCount{ 0 }; // cpu的系统核数
	QThreadPool m_threadPool;  // 线程池
	QString m_dingNoticePhones;  // 钉钉提醒人

};

class MyTask :public QThread {
	Q_OBJECT
public:
	MyTask(MainWindow& mainwindow);
	~MyTask() = default;

	void run() override;

signals:
	void task_finished();

private:
	MainWindow* m_mainwindow;

private:
	void sendDingDingNotice(QString& body, QString& url);

};


class ExcutePythonScript :public QRunnable {

public:
	ExcutePythonScript(QString& m_exe, QString& m_scipt, std::unique_ptr<QJsonObject> info);

	~ExcutePythonScript() = default;

	void run() override;

private:
	QString m_exe;
	QString m_script;
	std::unique_ptr<QJsonObject> m_info;

};


class PythonGetLabelCountSender : public QObject {
	Q_OBJECT

signals:
	void labelCount(QString taskName, int count);

public:
	void sendLabelCount(QString taskName, int count);

};

class PythonGetLabelCount : public QRunnable {
public:
	PythonGetLabelCount(const QString& taskName,
		const std::string& pyCommand, std::unique_ptr<PythonGetLabelCountSender> sender);
	~PythonGetLabelCount() = default;

	void run() override;

private:
	QString m_taskName;
	std::string m_pyCommand;
	std::unique_ptr<PythonGetLabelCountSender> m_sender;
};

