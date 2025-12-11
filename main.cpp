#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "util.h"
#include <QJsonObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (check_config()){
        return 1;
    }
    MainWindow w;
    w.show();
    return a.exec();
}

