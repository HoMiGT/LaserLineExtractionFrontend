#include "taskdailog.h"
#include "ui_taskdailog.h"
#include "util.h"
#include <QFileDialog>
#include <fstream>

namespace fs = std::filesystem;

TaskDailog::TaskDailog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TaskDailog)
{
    ui->setupUi(this);

    traverseDirectory(this->settings,false);
    ui->comboBox_setting->addItems(this->settings);

    fs::path setting_path = fs::current_path();
    setting_path.append("settings");
    setting_path.append("BaseSetting.json");

    auto jsonObj = readJsonFile(setting_path);
    auto temp = jsonObj.value();
    open_path = jsonObj.value().value("extract_path").toString();

}

TaskDailog::~TaskDailog()
{
    delete ui;
}

void TaskDailog::on_pushButton_close_clicked()
{
    this->close();
}


void TaskDailog::on_pushButton_extractPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,"选择文件夹",open_path,QFileDialog::ShowDirsOnly);
    if (path.isEmpty()){return;}
    this->ui->lineEdit_extractPath->setText(path);
}


void TaskDailog::on_pushButton_ok_clicked()
{
    auto setting_index = this->ui->comboBox_setting->currentIndex();
    auto extract_path = this->ui->lineEdit_extractPath->text();
    if (setting_index<0 || extract_path.isEmpty()){
        QMessageBox::information(this,"提示","请选择配置或填写提取路径");
        return;
    }
    QPair<QString,QString> msg(this->ui->comboBox_setting->currentText(),extract_path);
    emit addTask(msg);

    QMessageBox::information(this,"提示","添加成功");
    this->close();
}

