#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <QMessageBox>
#include <algorithm>
#include <string>
#include "util.h"
#include <QJsonObject>

namespace fs = std::filesystem;

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

