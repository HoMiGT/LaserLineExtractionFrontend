#pragma once

#include <QDialog>
#include <QPair>
#include <QString>

#include "model.h"

namespace Ui {
class TaskDailog;
}

class TaskDailog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDailog(QWidget *parent = nullptr);
    ~TaskDailog();

signals:
    void addTask(QPair<QString,QString>);



private slots:
    void on_pushButton_close_clicked();

    void on_pushButton_extractPath_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::TaskDailog *ui;
    QStringList settings;
    QString open_path;

};

