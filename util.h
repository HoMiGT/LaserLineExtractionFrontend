#pragma once

#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonValue>
#include <optional>
#include <fstream>

namespace fs = std::filesystem;

void traverseDirectory(QStringList& files,bool isAll=true,bool isFile=true);

std::optional<QJsonObject> readJsonFile(const fs::path& file);

bool writeJsonFile(const fs::path& file,QJsonObject& jsonObj);

void baseSettingJson(std::shared_ptr<QJsonObject>& jsonObj);

void getExtractImageName(QStringList& files,fs::path& extractPath);

int getDirCount(QString& path);

int check_config();



