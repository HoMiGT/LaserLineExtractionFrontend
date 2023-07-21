#pragma once

#include <QMainWindow>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QStringList>
#include <QStringListModel>
#include <QMenu>
#include <QAction>

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

signals:
    void updateSetting();

private slots:
    void on_pushButton_noOk_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_dir_seedPath_clicked();

    void on_pushButton_dir_failedImage_clicked();

    void on_listView_settings_doubleClicked(const QModelIndex &index);

    void on_pushButton_pythonPath_clicked();

    void on_pushButton_ok_clicked();

    void on_pushButton_search_clicked();

    void deleteItem();

    void on_pushButton_pythonScript_clicked();

    void on_pushButton_extractFile_clicked();

private:
    Ui::SettingWindow *m_ui;
    QIntValidator *m_intValidator;
    QDoubleValidator *m_doubleValidator;
    QStringListModel *m_settingModelFiles;
    QStringList m_settingFiles;
    QMenu *m_listViewMenu;
    QAction *m_listViewActionDelete;

};
