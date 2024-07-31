#include "settingwindow.h"
#include "ui_settingwindow.h"
#include <QFileDialog>
#include <QValidator>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <fstream>
#include <QMessageBox>
#include <QString>
#include <QAbstractItemView>
#include "util.h"
#include <string>
#include <QFile>

namespace fs = std::filesystem;

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::SettingWindow)
{
    m_ui->setupUi(this);
    m_intValidator = new QIntValidator();
    m_doubleValidator = new QDoubleValidator();
    m_ui->lineEdit_width->setValidator(m_doubleValidator);
    m_ui->lineEdit_height->setValidator(m_doubleValidator);
    m_ui->lineEdit_x->setValidator(m_doubleValidator);
    m_ui->lineEdit_y->setValidator(m_doubleValidator);
    m_ui->lineEdit_sideLength->setValidator(m_intValidator);
    m_ui->lineEdit_labelWidth->setValidator(m_doubleValidator);
    m_ui->lineEdit_labelHeight->setValidator(m_doubleValidator);
    m_ui->lineEdit_parallelCount->setValidator(m_intValidator);
    m_ui->lineEdit_blockNum->setValidator(m_intValidator);


    traverseDirectory(this->m_settingFiles);
    if (!this->m_settingFiles.empty()){
        this->m_settingModelFiles = new QStringListModel(this->m_settingFiles);
        this->m_ui->listView_settings->setModel(this->m_settingModelFiles);
    }

    m_ui->listView_settings->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_ui->listView_settings->setSelectionMode(QAbstractItemView::SingleSelection);

    m_listViewMenu = new QMenu(this->m_ui->listView_settings);
    m_listViewActionDelete = new QAction(tr("删除"),this);
    m_listViewMenu->addAction(m_listViewActionDelete);

    connect(m_listViewActionDelete,&QAction::triggered,this,&SettingWindow::deleteItem);
    m_ui->listView_settings->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_ui->listView_settings,&QWidget::customContextMenuRequested,[this](const QPoint &pos){
        this->m_listViewMenu->popup(m_ui->listView_settings->mapToGlobal(pos));
    });

}


SettingWindow::~SettingWindow()
{
    delete m_listViewMenu;
    delete m_listViewActionDelete;
    delete m_settingModelFiles;
    delete m_intValidator;
    delete m_doubleValidator;
    delete m_ui;
}

void SettingWindow::on_pushButton_noOk_clicked()
{
    this->close();
}

void SettingWindow::on_pushButton_add_clicked()
{
	this->m_ui->stackedWidget->setCurrentIndex(1);
    this->m_ui->lineEdit_settingName->clear();
    this->m_ui->lineEdit_width->clear();
    this->m_ui->lineEdit_height->clear();
    this->m_ui->lineEdit_x->clear();
    this->m_ui->lineEdit_y->clear();
    this->m_ui->lineEdit_sideLength->clear();
    this->m_ui->lineEdit_labelWidth->clear();
    this->m_ui->lineEdit_labelHeight->clear();
    this->m_ui->lineEdit_blockNum->clear();
}


void SettingWindow::on_pushButton_clear_clicked()
{
    int index = this->m_ui->stackedWidget->currentIndex();
    if (index==1){
        this->m_ui->lineEdit_settingName->clear();
        this->m_ui->lineEdit_width->clear();
        this->m_ui->lineEdit_height->clear();
        this->m_ui->lineEdit_x->clear();
        this->m_ui->lineEdit_y->clear();
        this->m_ui->lineEdit_sideLength->clear();
        this->m_ui->lineEdit_labelWidth->clear();
        this->m_ui->lineEdit_labelHeight->clear();
        this->m_ui->lineEdit_blockNum->clear();
    }else if(index==0){
        if(QMessageBox::question(this,"清除基础配置警告","请确认是否要清除基础配置！！！") == QMessageBox::StandardButton::Yes){
            this->m_ui->lineEdit_extractFile->clear();
            this->m_ui->lineEdit_seedSavePath->clear();
            this->m_ui->lineEdit_failedImagePath->clear();
            this->m_ui->checkBox_uploadServer->setChecked(false);
            this->m_ui->lineEdit_dingTalk->clear();
            this->m_ui->checkBox_dingTalk->setChecked(false);
            this->m_ui->lineEdit_pythonPath->clear();
            this->m_ui->lineEdit_pythonScript->clear();
            this->m_ui->lineEdit_parallelCount->clear();
        }
    }
}


void SettingWindow::on_pushButton_dir_seedPath_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,"选择文件夹","./",QFileDialog::ShowDirsOnly);
    if (path.isEmpty()){return;}
    this->m_ui->lineEdit_seedSavePath->setText(path);
}


void SettingWindow::on_pushButton_dir_failedImage_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,"选择文件夹","./",QFileDialog::ShowDirsOnly);
    if (path.isEmpty()){return;}
    this->m_ui->lineEdit_failedImagePath->setText(path);
}


void SettingWindow::on_listView_settings_doubleClicked(const QModelIndex &index)
{
    QVariant data = index.data(Qt::DisplayRole);
    QString text = data.toString();

    fs::path currentPath = fs::current_path();

    std::string filePath("settings/");

    if (text=="BaseSetting"){
        this->m_ui->stackedWidget->setCurrentIndex(0);
        filePath += text.toStdString() + ".json";

        currentPath.append(filePath);
        auto optJson = readJsonFile(currentPath);
        if (!optJson.has_value()){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Icon::Critical);
            msgBox.setText("路径找不到请核对: "+QString::fromStdString(currentPath.string()));
            msgBox.show();
            return ;
        }
        auto json = optJson.value();
        this->m_ui->lineEdit_extractFile->setText(json.value("extract_path").toString()); // 提取文件路径
        this->m_ui->lineEdit_seedSavePath->setText(json.value("upload_save_path").toString()); // 种子保存路径
        this->m_ui->lineEdit_failedImagePath->setText(json.value("failed_image_path").toString()); // 失败图片路径
        this->m_ui->checkBox_uploadServer->setChecked(json.value("is_upload_server").toBool()); // 是否上传服务器
        this->m_ui->lineEdit_dingTalk->setText(json.value("ding_ding_url").toString()); // 钉钉通知链接
        this->m_ui->checkBox_dingTalk->setChecked(json.value("is_ding_notice").toBool()); // 是否通知钉钉
        this->m_ui->lineEdit_pythonPath->setText(json.value("python_exe_path").toString()); // python执行路径
        this->m_ui->lineEdit_pythonScript->setText(json.value("python_script_path").toString()); // python 执行脚本的路径
        this->m_ui->lineEdit_parallelCount->setText(QString::number(json.value("parallel_count").toInt()));  // 任务并行数
    } else{
        this->m_ui->stackedWidget->setCurrentIndex(1);
        filePath += text.toStdString() + ".json";
        currentPath.append(filePath);
        auto optJson = readJsonFile(currentPath);
        if (!optJson.has_value()){
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Icon::Critical);
            msgBox.setText("路径找不到请核对: "+QString::fromStdString(currentPath.string()));
            msgBox.show();
            return ;
        }
        auto json = optJson.value();
        this->m_ui->lineEdit_settingName->setText(json.value("setting_name").toString());
        this->m_ui->lineEdit_width->setText(QString::number(json.value("extract_width").toDouble()));
        this->m_ui->lineEdit_height->setText(QString::number(json.value("extract_height").toDouble()));
        this->m_ui->lineEdit_x->setText(QString::number(json.value("extract_x").toDouble()));
        this->m_ui->lineEdit_y->setText(QString::number(json.value("extract_y").toDouble()));
        this->m_ui->lineEdit_sideLength->setText(QString::number(json.value("extract_sideLength").toInt()));
        this->m_ui->lineEdit_labelWidth->setText(QString::number(json.value("label_width").toDouble()));
        this->m_ui->lineEdit_labelHeight->setText(QString::number(json.value("label_height").toDouble()));
        if (json.contains("block_number")){
            this->m_ui->lineEdit_blockNum->setText(QString::number(json.value("block_number").toInt()));
        }else{
            this->m_ui->lineEdit_blockNum->setText(QString::number(10));
        }
    }
}


void SettingWindow::on_pushButton_pythonPath_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"选择文件","./",tr("Exe files(*.exe)"));
    if (path.isEmpty()){return;}
    this->m_ui->lineEdit_pythonPath->setText(path);
}


void SettingWindow::on_pushButton_ok_clicked()
{
    auto index = this->m_ui->stackedWidget->currentIndex();
    if (index==1){ // 其他配置保存
        QString setting_name = this->m_ui->lineEdit_settingName->text();// 配置名称
        QString extract_width_str = this->m_ui->lineEdit_width->text();// 提取宽
        QString extract_height_str = this->m_ui->lineEdit_height->text(); // 高
        QString extract_x_str = this->m_ui->lineEdit_x->text(); // x
        QString extract_y_str = this->m_ui->lineEdit_y->text(); // y
        QString extract_sideLength_str = this->m_ui->lineEdit_sideLength->text(); // 边长
        QString label_width_str = this->m_ui->lineEdit_labelWidth->text(); // 标签宽
        QString label_height_str = this->m_ui->lineEdit_labelHeight->text(); // 标签高
        QString block_num_str = this->m_ui->lineEdit_blockNum->text().isEmpty() ? this->m_ui->lineEdit_blockNum->placeholderText().isEmpty() ? "10" : this->m_ui->lineEdit_blockNum->placeholderText() : this->m_ui->lineEdit_blockNum->text();  // 块数量

        if (setting_name.isEmpty() || extract_width_str.isEmpty() || extract_height_str.isEmpty()){
            QMessageBox::information(this,"提示","配置名称、二维码边长或提取宽高不允许为空");
            return;
        };

        double extract_width = extract_width_str.toDouble();
        double extract_height = extract_height_str.toDouble();
        double extract_x = extract_x_str.toDouble();
        double extract_y = extract_y_str.toDouble();
        int extract_sideLength = extract_sideLength_str.toInt();
        double label_width = label_width_str.toDouble();
        double label_height = label_height_str.toDouble();
        int block_number = block_num_str.toInt();

        QJsonObject jsonObj;
        jsonObj["setting_name"] = setting_name;
        jsonObj["extract_width"] = extract_width;
        jsonObj["extract_height"] = extract_height;
        jsonObj["extract_x"] = extract_x;
        jsonObj["extract_y"] = extract_y;
        jsonObj["extract_sideLength"] = extract_sideLength;
        jsonObj["label_width"] = label_width;
        jsonObj["label_height"] = label_height;
        jsonObj["block_number"] = block_number;

        fs::path setting_file_path = fs::current_path();
        setting_file_path.append("settings");
        setting_file_path.append(setting_name.toStdString() + ".json");

        if (fs::exists(setting_file_path)){
            if (QMessageBox::question(this,"更新提取配置","已经有同名配置，请确认是否要更新！") == QMessageBox::StandardButton::Yes){
                if (!writeJsonFile(setting_file_path,jsonObj)){
                    QMessageBox::information(this,"更新提取配置","更新提取配置失败!");
                    return;
                }
                QMessageBox::information(this,"更新提取配置","更新提取配置成功!");
                return;
            }
        }else{
            if (!writeJsonFile(setting_file_path,jsonObj)){
                QMessageBox::information(this,"新增提取配置","新增提取配置失败!");
                return;
            }
            QMessageBox::information(this,"新增提取配置","新增提取配置成功!");
            this->m_settingFiles.clear();
            delete this->m_settingModelFiles;
            this->m_settingModelFiles=nullptr;
            traverseDirectory(this->m_settingFiles);
            if (!this->m_settingFiles.empty()){
                this->m_settingModelFiles = new QStringListModel(this->m_settingFiles);
                this->m_ui->listView_settings->setModel(this->m_settingModelFiles);
            }
            return;
        }

    }else if(index == 0){  // 基础配置保存
        if (QMessageBox::question(this,"更新基础配置","请确认是否要更新基础配置！！！") == QMessageBox::StandardButton::Yes){

            QString extract_path = this->m_ui->lineEdit_extractFile->text();
            QString upload_save_path = this->m_ui->lineEdit_seedSavePath->text();
            QString failed_image_path = this->m_ui->lineEdit_failedImagePath->text();
            bool is_upload_server = this->m_ui->checkBox_uploadServer->isChecked();
            QString ding_ding_url = this->m_ui->lineEdit_dingTalk->text();
            bool is_ding_notice = this->m_ui->checkBox_dingTalk->isChecked();
            QString python_exe_path = this->m_ui->lineEdit_pythonPath->text();
            QString python_script_path = this->m_ui->lineEdit_pythonScript->text();
            int parallel_count = this->m_ui->lineEdit_parallelCount->text().toInt();

            QJsonObject jsonObj;
            jsonObj["extract_path"] = extract_path; // 提取文件路径
            jsonObj["upload_save_path"] = upload_save_path; // 种子保存路径
            jsonObj["failed_image_path"] = failed_image_path; // 失败图片路径
            jsonObj["is_upload_server"] = is_upload_server; // 是否上传服务器
            jsonObj["ding_ding_url"] = ding_ding_url; // 钉钉通知链接
            jsonObj["is_ding_notice"] = is_ding_notice; // 是否通知钉钉
            jsonObj["python_exe_path"] = python_exe_path; // python执行路径
            jsonObj["python_script_path"] = python_script_path; // python 脚本的执行路径
            jsonObj["parallel_count"] = parallel_count; // 并行数据


            fs::path setting_file_path = fs::current_path();
            setting_file_path.append("settings");
            setting_file_path.append("BaseSetting.json");

            if (!writeJsonFile(setting_file_path,jsonObj)){
                QMessageBox::information(this,"更新基础配置","更新基础配置失败!");
                return;
            }
            emit this->updateSetting();
            QMessageBox::information(this,"更新基础配置","更新基础配置成功!");
            return;
        }
    }
}


void SettingWindow::on_pushButton_search_clicked()
{
    QString text = this->m_ui->lineEdit_search->text();
    if (text.isEmpty()){
        this->m_ui->listView_settings->setModel(this->m_settingModelFiles);
        return;
    }else{
        QStringList temp;
        for (auto& item:this->m_settingFiles){
            if (text == item){
                temp.emplace_back(item);
            }
        }
        auto tempModel = new QStringListModel(temp);
        this->m_ui->listView_settings->setModel(tempModel);
        delete tempModel;
        tempModel=nullptr;
    }

}

void SettingWindow::deleteItem()
{

    if (QMessageBox::question(this,"删除配置","是否要删除选中的配置",QMessageBox::StandardButton::Yes|QMessageBox::StandardButton::No, QMessageBox::StandardButton::No)==QMessageBox::StandardButton::No){
        return;
    }

    auto currentIndex = this->m_ui->listView_settings->currentIndex();
    QVariant data = currentIndex.data();
    QString text = data.toString();

    if (text.isEmpty()) {return;}
    if (text == QString("BaseSetting")){
        QMessageBox::information(this,"提示","BaseSetting不允许删除");
        return;
    }

    fs::path file = fs::current_path();
    file.append("settings");
    file.append(text.toStdString() + ".json");

    if (!fs::exists(file)) {
        QMessageBox::information(this,"提示","要删除的文件不存在,请核对后重试");
        return;
    }

    QString path = QString::fromStdString(file.string());
    QFile::remove(path);

    this->m_settingFiles.clear();
    delete this->m_settingModelFiles;
    this->m_settingModelFiles = nullptr;
    traverseDirectory(this->m_settingFiles);
    if (!this->m_settingFiles.empty()){
        this->m_settingModelFiles = new QStringListModel(this->m_settingFiles);
        this->m_ui->listView_settings->setModel(this->m_settingModelFiles);
    }

    this->m_ui->lineEdit_settingName->clear();
    this->m_ui->lineEdit_width->clear();
    this->m_ui->lineEdit_height->clear();
    this->m_ui->lineEdit_x->clear();
    this->m_ui->lineEdit_y->clear();
    this->m_ui->lineEdit_sideLength->clear();
    this->m_ui->lineEdit_labelWidth->clear();
    this->m_ui->lineEdit_labelHeight->clear();
    this->m_ui->lineEdit_blockNum->clear();

    QMessageBox::information(this,"提示","删除文件成功");

}


void SettingWindow::on_pushButton_pythonScript_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,"选择文件","./",tr("Python files(*.py)"));
    if (path.isEmpty()){return;}
    this->m_ui->lineEdit_pythonScript->setText(path);
}


void SettingWindow::on_pushButton_extractFile_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this,"选择文件夹","./",QFileDialog::ShowDirsOnly);
    if (path.isEmpty()){return;}
    this->m_ui->lineEdit_extractFile->setText(path);
}

