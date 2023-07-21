/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_setting;
    QAction *action_exit;
    QAction *action_help;
    QAction *action_addTask;
    QAction *action_clearList;
    QAction *action_startTask;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox_taskList;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView_taskList;
    QGroupBox *groupBox_taskStates;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label_taskName;
    QLineEdit *lineEdit_taskName;
    QLabel *label_3;
    QPushButton *pushButton_extractImagePath;
    QLabel *label_seedPath;
    QPushButton *pushButton_seedPath;
    QLabel *label_failedImagePath;
    QPushButton *pushButton_failedImagePath;
    QLabel *label;
    QLCDNumber *lcdNumber_success;
    QLabel *label_2;
    QLCDNumber *lcdNumber_fail;
    QLabel *label_4;
    QProgressBar *progressBar_successRatio;
    QLabel *label_5;
    QLineEdit *lineEdit_spendTime;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_help;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setWindowModality(Qt::ApplicationModal);
        MainWindow->resize(1241, 734);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action_setting = new QAction(MainWindow);
        action_setting->setObjectName("action_setting");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/action_setting.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_setting->setIcon(icon);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName("action_exit");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/exit.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon1);
        action_help = new QAction(MainWindow);
        action_help->setObjectName("action_help");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/menu_help.svg"), QSize(), QIcon::Normal, QIcon::Off);
        action_help->setIcon(icon2);
        QFont font;
        font.setPointSize(12);
        action_help->setFont(font);
        action_addTask = new QAction(MainWindow);
        action_addTask->setObjectName("action_addTask");
        QIcon icon3;
        QString iconThemeName = QString::fromUtf8("appointment-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8(":/Icon/add_task.svg"), QSize(), QIcon::Normal, QIcon::Off);
        }
        action_addTask->setIcon(icon3);
        action_clearList = new QAction(MainWindow);
        action_clearList->setObjectName("action_clearList");
        QIcon icon4;
        iconThemeName = QString::fromUtf8("document-revert");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8(":/Icon/clear_task.svg"), QSize(), QIcon::Normal, QIcon::Off);
        }
        action_clearList->setIcon(icon4);
        action_startTask = new QAction(MainWindow);
        action_startTask->setObjectName("action_startTask");
        QIcon icon5;
        iconThemeName = QString::fromUtf8("go-next");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8(":/Icon/start_no.svg"), QSize(), QIcon::Normal, QIcon::Off);
        }
        action_startTask->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setFont(font);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_8->setSizeConstraint(QLayout::SetNoConstraint);
        groupBox_taskList = new QGroupBox(centralwidget);
        groupBox_taskList->setObjectName("groupBox_taskList");
        sizePolicy.setHeightForWidth(groupBox_taskList->sizePolicy().hasHeightForWidth());
        groupBox_taskList->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox_taskList);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableView_taskList = new QTableView(groupBox_taskList);
        tableView_taskList->setObjectName("tableView_taskList");
        sizePolicy.setHeightForWidth(tableView_taskList->sizePolicy().hasHeightForWidth());
        tableView_taskList->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(tableView_taskList);


        horizontalLayout_8->addWidget(groupBox_taskList);

        groupBox_taskStates = new QGroupBox(centralwidget);
        groupBox_taskStates->setObjectName("groupBox_taskStates");
        sizePolicy.setHeightForWidth(groupBox_taskStates->sizePolicy().hasHeightForWidth());
        groupBox_taskStates->setSizePolicy(sizePolicy);
        groupBox_taskStates->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_3 = new QVBoxLayout(groupBox_taskStates);
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetNoConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(15);
        label_taskName = new QLabel(groupBox_taskStates);
        label_taskName->setObjectName("label_taskName");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_taskName->sizePolicy().hasHeightForWidth());
        label_taskName->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_taskName);

        lineEdit_taskName = new QLineEdit(groupBox_taskStates);
        lineEdit_taskName->setObjectName("lineEdit_taskName");
        sizePolicy1.setHeightForWidth(lineEdit_taskName->sizePolicy().hasHeightForWidth());
        lineEdit_taskName->setSizePolicy(sizePolicy1);
        lineEdit_taskName->setMinimumSize(QSize(0, 40));
        lineEdit_taskName->setMaximumSize(QSize(16777215, 40));
        lineEdit_taskName->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_taskName);

        label_3 = new QLabel(groupBox_taskStates);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        pushButton_extractImagePath = new QPushButton(groupBox_taskStates);
        pushButton_extractImagePath->setObjectName("pushButton_extractImagePath");
        pushButton_extractImagePath->setMinimumSize(QSize(0, 40));
        pushButton_extractImagePath->setMaximumSize(QSize(16777215, 40));
        pushButton_extractImagePath->setStyleSheet(QString::fromUtf8("QPushButton{text-align : left;}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_extractImagePath);

        label_seedPath = new QLabel(groupBox_taskStates);
        label_seedPath->setObjectName("label_seedPath");
        sizePolicy1.setHeightForWidth(label_seedPath->sizePolicy().hasHeightForWidth());
        label_seedPath->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_seedPath);

        pushButton_seedPath = new QPushButton(groupBox_taskStates);
        pushButton_seedPath->setObjectName("pushButton_seedPath");
        sizePolicy1.setHeightForWidth(pushButton_seedPath->sizePolicy().hasHeightForWidth());
        pushButton_seedPath->setSizePolicy(sizePolicy1);
        pushButton_seedPath->setMinimumSize(QSize(0, 40));
        pushButton_seedPath->setMaximumSize(QSize(16777215, 40));
        pushButton_seedPath->setStyleSheet(QString::fromUtf8("QPushButton{text-align : left;}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButton_seedPath);

        label_failedImagePath = new QLabel(groupBox_taskStates);
        label_failedImagePath->setObjectName("label_failedImagePath");
        sizePolicy1.setHeightForWidth(label_failedImagePath->sizePolicy().hasHeightForWidth());
        label_failedImagePath->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_failedImagePath);

        pushButton_failedImagePath = new QPushButton(groupBox_taskStates);
        pushButton_failedImagePath->setObjectName("pushButton_failedImagePath");
        sizePolicy1.setHeightForWidth(pushButton_failedImagePath->sizePolicy().hasHeightForWidth());
        pushButton_failedImagePath->setSizePolicy(sizePolicy1);
        pushButton_failedImagePath->setMinimumSize(QSize(0, 40));
        pushButton_failedImagePath->setMaximumSize(QSize(16777215, 40));
        pushButton_failedImagePath->setStyleSheet(QString::fromUtf8("QPushButton{text-align : left;}"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButton_failedImagePath);

        label = new QLabel(groupBox_taskStates);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        lcdNumber_success = new QLCDNumber(groupBox_taskStates);
        lcdNumber_success->setObjectName("lcdNumber_success");
        sizePolicy1.setHeightForWidth(lcdNumber_success->sizePolicy().hasHeightForWidth());
        lcdNumber_success->setSizePolicy(sizePolicy1);
        lcdNumber_success->setMinimumSize(QSize(0, 40));
        lcdNumber_success->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(false);
        lcdNumber_success->setFont(font1);
        lcdNumber_success->setFrameShape(QFrame::Box);
        lcdNumber_success->setFrameShadow(QFrame::Sunken);
        lcdNumber_success->setDigitCount(20);
        lcdNumber_success->setSegmentStyle(QLCDNumber::Flat);

        formLayout->setWidget(4, QFormLayout::FieldRole, lcdNumber_success);

        label_2 = new QLabel(groupBox_taskStates);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_2);

        lcdNumber_fail = new QLCDNumber(groupBox_taskStates);
        lcdNumber_fail->setObjectName("lcdNumber_fail");
        sizePolicy1.setHeightForWidth(lcdNumber_fail->sizePolicy().hasHeightForWidth());
        lcdNumber_fail->setSizePolicy(sizePolicy1);
        lcdNumber_fail->setMinimumSize(QSize(0, 40));
        lcdNumber_fail->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        lcdNumber_fail->setFont(font2);
        lcdNumber_fail->setFrameShadow(QFrame::Sunken);
        lcdNumber_fail->setLineWidth(1);
        lcdNumber_fail->setMidLineWidth(0);
        lcdNumber_fail->setSmallDecimalPoint(false);
        lcdNumber_fail->setDigitCount(20);
        lcdNumber_fail->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_fail->setProperty("value", QVariant(0.000000000000000));
        lcdNumber_fail->setProperty("intValue", QVariant(0));

        formLayout->setWidget(5, QFormLayout::FieldRole, lcdNumber_fail);

        label_4 = new QLabel(groupBox_taskStates);
        label_4->setObjectName("label_4");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        progressBar_successRatio = new QProgressBar(groupBox_taskStates);
        progressBar_successRatio->setObjectName("progressBar_successRatio");
        progressBar_successRatio->setMinimumSize(QSize(0, 40));
        progressBar_successRatio->setMaximumSize(QSize(16777215, 40));
        progressBar_successRatio->setValue(0);

        formLayout->setWidget(6, QFormLayout::FieldRole, progressBar_successRatio);

        label_5 = new QLabel(groupBox_taskStates);
        label_5->setObjectName("label_5");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_5);

        lineEdit_spendTime = new QLineEdit(groupBox_taskStates);
        lineEdit_spendTime->setObjectName("lineEdit_spendTime");
        lineEdit_spendTime->setMinimumSize(QSize(0, 40));
        lineEdit_spendTime->setMaximumSize(QSize(16777215, 40));
        lineEdit_spendTime->setReadOnly(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEdit_spendTime);


        verticalLayout_3->addLayout(formLayout);


        horizontalLayout_8->addWidget(groupBox_taskStates);


        verticalLayout->addLayout(horizontalLayout_8);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1241, 27));
        menubar->setFont(font);
        menubar->setDefaultUp(false);
        menu_file = new QMenu(menubar);
        menu_file->setObjectName("menu_file");
        menu_file->setFont(font);
        menu_file->setTearOffEnabled(false);
        menu_help = new QMenu(menubar);
        menu_help->setObjectName("menu_help");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(action_setting);
        menu_file->addSeparator();
        menu_file->addAction(action_exit);
        menu_help->addAction(action_help);
        toolBar->addAction(action_addTask);
        toolBar->addSeparator();
        toolBar->addAction(action_clearList);
        toolBar->addSeparator();
        toolBar->addAction(action_startTask);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206\351\225\255\345\260\204\346\217\220\345\217\226", nullptr));
        action_setting->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        action_setting->setIconText(QCoreApplication::translate("MainWindow", "setting", nullptr));
#if QT_CONFIG(statustip)
        action_setting->setStatusTip(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S \350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_setting->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action_exit->setIconText(QCoreApplication::translate("MainWindow", "exit", nullptr));
#if QT_CONFIG(statustip)
        action_exit->setStatusTip(QCoreApplication::translate("MainWindow", "Ctrl+Q \351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_exit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_help->setText(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
#if QT_CONFIG(statustip)
        action_help->setStatusTip(QCoreApplication::translate("MainWindow", "Ctrl+P \345\270\256\345\212\251", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_help->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        action_addTask->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
#if QT_CONFIG(tooltip)
        action_addTask->setToolTip(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        action_addTask->setStatusTip(QCoreApplication::translate("MainWindow", "Ctrl+A \346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_addTask->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        action_clearList->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\344\273\273\345\212\241", nullptr));
#if QT_CONFIG(tooltip)
        action_clearList->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        action_clearList->setStatusTip(QCoreApplication::translate("MainWindow", "Ctrl+Shift+C \346\270\205\351\231\244\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_clearList->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_startTask->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\344\273\273\345\212\241", nullptr));
#if QT_CONFIG(tooltip)
        action_startTask->setToolTip(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        action_startTask->setStatusTip(QCoreApplication::translate("MainWindow", "Ctrl+R \345\274\200\345\247\213\344\273\273\345\212\241", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        action_startTask->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_taskList->setTitle(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\345\210\227\350\241\250", nullptr));
        groupBox_taskStates->setTitle(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\347\212\266\346\200\201", nullptr));
        label_taskName->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\345\220\215\347\247\260:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\217\220\345\217\226\345\233\276\347\211\207\350\267\257\345\276\204:", nullptr));
        pushButton_extractImagePath->setText(QString());
        label_seedPath->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\347\247\215\345\255\220\350\267\257\345\276\204:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_seedPath->setToolTip(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\346\211\223\345\274\200\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_seedPath->setText(QString());
        label_failedImagePath->setText(QCoreApplication::translate("MainWindow", "\345\244\261\350\264\245\345\233\276\347\211\207\350\267\257\345\276\204:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_failedImagePath->setToolTip(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\346\211\223\345\274\200\346\226\207\344\273\266\350\267\257\345\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_failedImagePath->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\346\217\220\345\217\226\346\210\220\345\212\237\344\270\252\346\225\260:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\217\220\345\217\226\345\244\261\350\264\245\344\270\252\346\225\260:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\217\220\345\217\226\346\210\220\345\212\237\347\216\207:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\350\200\227\346\227\266:", nullptr));
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_help->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
