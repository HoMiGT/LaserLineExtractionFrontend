#include "util.h"
#include <QDir>
#include <iostream>
#include <string>
#include <cstdio>
#include <QRegularExpression>

std::optional<QJsonObject> readJsonFile(const fs::path& file)
{
	QString QStrFile = QString::fromStdString(file.string()).replace("\\", "/");

	QFile jsonFile(QStrFile);
	if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return std::nullopt;
	}
	QByteArray jsonData = jsonFile.readAll();
	jsonFile.close();

	QJsonParseError parseError;
	QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
	if (parseError.error != QJsonParseError::NoError) {
		return std::nullopt;
	}

	if (!jsonDoc.isObject()) {
		return std::nullopt;
	}

	QJsonObject jsonObj = jsonDoc.object();
	return jsonObj;

}



bool writeJsonFile(const fs::path& file, QJsonObject& jsonObj)
{
	std::string strFile = file.string();
	QString QStrFile = QString::fromStdString(strFile).replace("\\", "/");
	QJsonDocument jsonDoc(jsonObj);

	QFile jsonFile(QStrFile);
	if (!jsonFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
		return false;
	}
	jsonFile.write(jsonDoc.toJson());
	jsonFile.close();
	return true;
}

void traverseDirectory(QStringList& files, bool isAll, bool isFile) {
	fs::path path = fs::current_path();
	path.append("settings");
	if (!fs::exists(path)) {
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Icon::Critical);
		msgBox.setText(QString("settings文件夹不存在，请重试！"));
		msgBox.show();
		return;
	}

	for (const auto& entry : fs::directory_iterator(path)) {
		if (isFile) {
			if (fs::is_directory(entry)) {
				continue;
			}
			auto file = entry.path().stem().generic_string();
			if (!isAll && file == "BaseSetting") { continue; }
			files.emplace_back(QString::fromStdString(file));
		}
		else {
			if (!fs::is_directory(entry)) {
				continue;
			}
			files.emplace_back(QString::fromStdString(entry.path().generic_string()));
		}
	}
}

void baseSettingJson(std::shared_ptr<QJsonObject>& jsonObj)
{
	fs::path setting_path = fs::current_path();
	setting_path.append("settings");
	setting_path.append("BaseSetting.json");

	auto temp = readJsonFile(setting_path);
	if (!temp.has_value()) {
		QMessageBox::critical(nullptr, "提示", "加载配置文件失败！");
		return;
	}
	jsonObj = std::make_shared<QJsonObject>(temp.value());
}

void getExtractImageName(QStringList& files, fs::path& extractPath, QString& task_name, int cpu_count)
{
	if (!fs::exists(extractPath)) {
		QMessageBox::critical(nullptr, "错误", "提取的文件夹路径不存在,请核对");
		return;
	}
	QMap<int, std::shared_ptr<QFile>> csvFiles;

	int file_count = 0;
	for (auto i = 0; i < cpu_count; ++i) {
		fs::path customeCsv = fs::current_path();
		customeCsv.append("csvs");
		auto file_name = task_name + "_" + QString::number(i) + ".csv";
		customeCsv.append(file_name.toStdString());
		auto csvFile = std::make_shared<QFile>(customeCsv);
		if (csvFile->open(QIODevice::WriteOnly | QIODevice::Append)) {
			QTextStream stream(csvFile.get());
			stream << "FileName\n";
			csvFile->close();
			csvFiles.insert(file_count, csvFile);
			files.append(QString::fromStdString(customeCsv.string()));
			file_count++;
		}

	}

	int index = 0;
	for (const auto& entry : fs::directory_iterator(extractPath)) {
		if (!fs::is_directory(entry)) {
			auto file = entry.path().filename().generic_string();
			auto i = index % file_count;
			auto fhandle = csvFiles[i];
			if (fhandle->open(QIODevice::WriteOnly | QIODevice::Append)) {
				QTextStream stream(fhandle.get());
				stream << QString::fromStdString(file);
				stream << "\n";
				fhandle->close();
				index++;
			}
		}
	}
}

int getDirCount(QString& path)
{
	QDir dir(path);
	QFileInfoList folders = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
	int folderCount = folders.count();
	return folderCount;
}




inline int check_config_directories(fs::path& setting_path, fs::path& upload_path, fs::path& failed_path) {
	// 检查 settings的文件是否存在
	if (!fs::exists(setting_path)) {
		if (!fs::create_directories(setting_path)) {
			QMessageBox::critical(nullptr, "错误", "settings文件夹创建失败，请手动创建后，再尝试重新打开程序!");
			return 1;
		}
	}

	// 检查默认upload seed的文件夹是否存在
	if (!fs::exists(upload_path)) {
		if (!fs::create_directories(upload_path)) {
			QMessageBox::critical(nullptr, "错误", "UploadSeed文件夹创建失败，请手动创建后，再尝试重新打开程序!");
			return 1;
		}
	}

	// 检查 failed seed的文件夹是否存在
	if (!fs::exists(failed_path)) {
		if (!fs::create_directories(failed_path)) {
			QMessageBox::critical(nullptr, "错误", "FailedSeed文件夹创建失败，请手动创建后，再尝试重新打开程序!");
			return 1;
		}
	}
	return 0;
}

inline int check_config_file(fs::path& setting_path, fs::path& project_path, fs::path& upload_path, fs::path& failed_path) {

	if (fs::exists(setting_path)) { return 0; }

	// 创建默认的基础配置
	QJsonObject jsonObj;
	jsonObj["extract_path"] = QString::fromStdString(project_path.string()).replace("\\", "/"); // 提取文件路径
	jsonObj["upload_save_path"] = QString::fromStdString(upload_path.string()).replace("\\", "/"); // 种子保存路径
	jsonObj["failed_image_path"] = QString::fromStdString(failed_path.string()).replace("\\", "/"); // 失败图片路径
	jsonObj["is_upload_server"] = true; // 是否上传服务器
	jsonObj["ding_ding_url"] = ""; // 钉钉通知链接
	jsonObj["is_ding_notice"] = true; // 是否通知钉钉
	jsonObj["python_exe_path"] = ""; // python执行路径
	jsonObj["python_script_path"] = "";  //python 脚本执行路径
	jsonObj["parallel_count"] = 1;  // 任务并行的个数

	if (!writeJsonFile(setting_path, jsonObj)) {
		return 1;
	}
	return 0;
}


int check_config() {

	fs::path setting_path = fs::current_path();
	setting_path.append("settings");
	fs::path upload_path = fs::current_path();
	upload_path.append("UploadSeed");
	fs::path failed_path = fs::current_path();
	failed_path.append("FailedSeed");

	int i1 = check_config_directories(setting_path, upload_path, failed_path);
	if (i1) { return i1; }

	fs::path project_path = fs::current_path();
	fs::path setting_file_path = fs::current_path();
	setting_file_path.append("settings");
	setting_file_path.append("BaseSetting.json");
	int i2 = check_config_file(setting_file_path, project_path, upload_path, failed_path);
	if (i2) { return i2; }
	return 0;
}

void logToFile(const QString& message) {
	QFile file("log.txt");
	if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
		QTextStream stream(&file);
		stream << QDateTime::currentDateTime().toString(Qt::ISODate) << " " << message << "\n";
		file.close();
	}
	else {
		// 处理文件打开失败的情况
	}
}

void clear_folder() {
	fs::path customeCsv = fs::current_path();
	customeCsv.append("csvs");
	const QString& folderPath = QString::fromStdString(customeCsv.string());
	QDir folder(folderPath);
	if (!folder.exists()) {
		qDebug() << "文件夹不存在";
		return;
	}

	folder.setFilter(QDir::Files | QDir::NoDotAndDotDot);
	for (const QFileInfo& fileInfo : folder.entryInfoList()) {
		if (!folder.remove(fileInfo.absoluteFilePath())) {
			qDebug() << "无法删除文件" << fileInfo.absoluteFilePath();
		}
	}
}

int execute_python_script(const std::string& python_script) {
	int result = { -1 };
	std::string py_result;
	try {
		FILE* pipe = _popen(python_script.c_str(), "r");
		if (!pipe) {
			return result;
		}
		char buffer[128];
		while (!feof(pipe)) {
			if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
				py_result += buffer;
			}
		}
		if (pipe) {
			_pclose(pipe);
		}
		QRegularExpression regex(R"(count_all:\s+(\d+))");
		QRegularExpressionMatch match = regex.match(QString::fromStdString(py_result));
		if (match.hasMatch()) {
			if (auto countAllValue = match.captured(1); !countAllValue.isEmpty()) {
				result = countAllValue.toInt();
			}
		}
	}
	catch (const std::exception& e) {
		qDebug() << "error: " << e.what();
	}
	return result;
}