/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QListView *listView_settings;
    QStackedWidget *stackedWidget;
    QWidget *page_base;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_base;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_base;
    QVBoxLayout *verticalLayout_9;
    QFormLayout *formLayout_3;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_extractFile;
    QPushButton *pushButton_extractFile;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *lineEdit_seedSavePath;
    QPushButton *pushButton_dir_seedPath;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *lineEdit_failedImagePath;
    QPushButton *pushButton_dir_failedImage;
    QLabel *label_7;
    QCheckBox *checkBox_uploadServer;
    QLabel *label_3;
    QLineEdit *lineEdit_dingTalk;
    QLabel *label_8;
    QCheckBox *checkBox_dingTalk;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *lineEdit_pythonPath;
    QPushButton *pushButton_pythonPath;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *lineEdit_pythonScript;
    QPushButton *pushButton_pythonScript;
    QLabel *label_2;
    QLineEdit *lineEdit_parallelCount;
    QLabel *label_16;
    QLineEdit *lineEdit_dingTalkPhones;
    QSpacerItem *verticalSpacer;
    QWidget *page_other;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_other;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_other;
    QVBoxLayout *verticalLayout_5;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_settingName;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit_width;
    QLineEdit *lineEdit_height;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_x;
    QLineEdit *lineEdit_y;
    QLabel *label_13;
    QLineEdit *lineEdit_sideLength;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *lineEdit_labelWidth;
    QLineEdit *lineEdit_labelHeight;
    QLabel *label_15;
    QLineEdit *lineEdit_blockNum;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_add;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_noOk;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName("SettingWindow");
        SettingWindow->resize(1149, 710);
        QFont font;
        font.setPointSize(12);
        SettingWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/action_setting.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        SettingWindow->setWindowIcon(icon);
        centralwidget = new QWidget(SettingWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_8 = new QHBoxLayout(centralwidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(5, -1, 5, -1);
        lineEdit_search = new QLineEdit(centralwidget);
        lineEdit_search->setObjectName("lineEdit_search");
        lineEdit_search->setMinimumSize(QSize(0, 40));
        lineEdit_search->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(centralwidget);
        pushButton_search->setObjectName("pushButton_search");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_search->sizePolicy().hasHeightForWidth());
        pushButton_search->setSizePolicy(sizePolicy1);
        pushButton_search->setMinimumSize(QSize(80, 40));
        pushButton_search->setMaximumSize(QSize(80, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/search.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_search->setIcon(icon1);
        pushButton_search->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_search);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 8);

        verticalLayout->addLayout(horizontalLayout);

        listView_settings = new QListView(centralwidget);
        listView_settings->setObjectName("listView_settings");

        verticalLayout->addWidget(listView_settings);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 8);

        horizontalLayout_2->addLayout(verticalLayout);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page_base = new QWidget();
        page_base->setObjectName("page_base");
        sizePolicy.setHeightForWidth(page_base->sizePolicy().hasHeightForWidth());
        page_base->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(page_base);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox_base = new QGroupBox(page_base);
        groupBox_base->setObjectName("groupBox_base");
        sizePolicy.setHeightForWidth(groupBox_base->sizePolicy().hasHeightForWidth());
        groupBox_base->setSizePolicy(sizePolicy);
        verticalLayout_6 = new QVBoxLayout(groupBox_base);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(20, 20, 20, 20);
        widget_base = new QWidget(groupBox_base);
        widget_base->setObjectName("widget_base");
        sizePolicy.setHeightForWidth(widget_base->sizePolicy().hasHeightForWidth());
        widget_base->setSizePolicy(sizePolicy);
        widget_base->setMinimumSize(QSize(0, 0));
        verticalLayout_9 = new QVBoxLayout(widget_base);
        verticalLayout_9->setObjectName("verticalLayout_9");
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_3->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(widget_base);
        label_10->setObjectName("label_10");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_10);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lineEdit_extractFile = new QLineEdit(widget_base);
        lineEdit_extractFile->setObjectName("lineEdit_extractFile");
        lineEdit_extractFile->setMinimumSize(QSize(0, 40));
        lineEdit_extractFile->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_6->addWidget(lineEdit_extractFile);

        pushButton_extractFile = new QPushButton(widget_base);
        pushButton_extractFile->setObjectName("pushButton_extractFile");
        pushButton_extractFile->setMinimumSize(QSize(80, 40));
        pushButton_extractFile->setMaximumSize(QSize(80, 40));

        horizontalLayout_6->addWidget(pushButton_extractFile);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout_6);

        label_5 = new QLabel(widget_base);
        label_5->setObjectName("label_5");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_seedSavePath = new QLineEdit(widget_base);
        lineEdit_seedSavePath->setObjectName("lineEdit_seedSavePath");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_seedSavePath->sizePolicy().hasHeightForWidth());
        lineEdit_seedSavePath->setSizePolicy(sizePolicy3);
        lineEdit_seedSavePath->setMinimumSize(QSize(0, 40));
        lineEdit_seedSavePath->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_7->addWidget(lineEdit_seedSavePath);

        pushButton_dir_seedPath = new QPushButton(widget_base);
        pushButton_dir_seedPath->setObjectName("pushButton_dir_seedPath");
        sizePolicy.setHeightForWidth(pushButton_dir_seedPath->sizePolicy().hasHeightForWidth());
        pushButton_dir_seedPath->setSizePolicy(sizePolicy);
        pushButton_dir_seedPath->setMinimumSize(QSize(80, 40));
        pushButton_dir_seedPath->setMaximumSize(QSize(80, 40));

        horizontalLayout_7->addWidget(pushButton_dir_seedPath);


        formLayout_3->setLayout(1, QFormLayout::FieldRole, horizontalLayout_7);

        label_6 = new QLabel(widget_base);
        label_6->setObjectName("label_6");
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_failedImagePath = new QLineEdit(widget_base);
        lineEdit_failedImagePath->setObjectName("lineEdit_failedImagePath");
        sizePolicy3.setHeightForWidth(lineEdit_failedImagePath->sizePolicy().hasHeightForWidth());
        lineEdit_failedImagePath->setSizePolicy(sizePolicy3);
        lineEdit_failedImagePath->setMinimumSize(QSize(0, 40));
        lineEdit_failedImagePath->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_9->addWidget(lineEdit_failedImagePath);

        pushButton_dir_failedImage = new QPushButton(widget_base);
        pushButton_dir_failedImage->setObjectName("pushButton_dir_failedImage");
        sizePolicy.setHeightForWidth(pushButton_dir_failedImage->sizePolicy().hasHeightForWidth());
        pushButton_dir_failedImage->setSizePolicy(sizePolicy);
        pushButton_dir_failedImage->setMinimumSize(QSize(80, 40));
        pushButton_dir_failedImage->setMaximumSize(QSize(80, 40));

        horizontalLayout_9->addWidget(pushButton_dir_failedImage);


        formLayout_3->setLayout(2, QFormLayout::FieldRole, horizontalLayout_9);

        label_7 = new QLabel(widget_base);
        label_7->setObjectName("label_7");
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_7);

        checkBox_uploadServer = new QCheckBox(widget_base);
        checkBox_uploadServer->setObjectName("checkBox_uploadServer");
        sizePolicy2.setHeightForWidth(checkBox_uploadServer->sizePolicy().hasHeightForWidth());
        checkBox_uploadServer->setSizePolicy(sizePolicy2);
        checkBox_uploadServer->setMinimumSize(QSize(40, 40));
        checkBox_uploadServer->setMaximumSize(QSize(40, 40));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, checkBox_uploadServer);

        label_3 = new QLabel(widget_base);
        label_3->setObjectName("label_3");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_3);

        lineEdit_dingTalk = new QLineEdit(widget_base);
        lineEdit_dingTalk->setObjectName("lineEdit_dingTalk");
        lineEdit_dingTalk->setMinimumSize(QSize(0, 40));
        lineEdit_dingTalk->setMaximumSize(QSize(16777215, 40));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lineEdit_dingTalk);

        label_8 = new QLabel(widget_base);
        label_8->setObjectName("label_8");
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_8);

        checkBox_dingTalk = new QCheckBox(widget_base);
        checkBox_dingTalk->setObjectName("checkBox_dingTalk");
        sizePolicy2.setHeightForWidth(checkBox_dingTalk->sizePolicy().hasHeightForWidth());
        checkBox_dingTalk->setSizePolicy(sizePolicy2);
        checkBox_dingTalk->setMinimumSize(QSize(40, 40));
        checkBox_dingTalk->setMaximumSize(QSize(40, 40));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, checkBox_dingTalk);

        label_11 = new QLabel(widget_base);
        label_11->setObjectName("label_11");

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lineEdit_pythonPath = new QLineEdit(widget_base);
        lineEdit_pythonPath->setObjectName("lineEdit_pythonPath");
        lineEdit_pythonPath->setMinimumSize(QSize(0, 40));
        lineEdit_pythonPath->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_10->addWidget(lineEdit_pythonPath);

        pushButton_pythonPath = new QPushButton(widget_base);
        pushButton_pythonPath->setObjectName("pushButton_pythonPath");
        pushButton_pythonPath->setMinimumSize(QSize(80, 40));
        pushButton_pythonPath->setMaximumSize(QSize(80, 40));

        horizontalLayout_10->addWidget(pushButton_pythonPath);


        formLayout_3->setLayout(6, QFormLayout::FieldRole, horizontalLayout_10);

        label_12 = new QLabel(widget_base);
        label_12->setObjectName("label_12");

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        lineEdit_pythonScript = new QLineEdit(widget_base);
        lineEdit_pythonScript->setObjectName("lineEdit_pythonScript");
        lineEdit_pythonScript->setMinimumSize(QSize(0, 40));
        lineEdit_pythonScript->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_11->addWidget(lineEdit_pythonScript);

        pushButton_pythonScript = new QPushButton(widget_base);
        pushButton_pythonScript->setObjectName("pushButton_pythonScript");
        pushButton_pythonScript->setMinimumSize(QSize(80, 40));
        pushButton_pythonScript->setMaximumSize(QSize(80, 40));

        horizontalLayout_11->addWidget(pushButton_pythonScript);


        formLayout_3->setLayout(7, QFormLayout::FieldRole, horizontalLayout_11);

        label_2 = new QLabel(widget_base);
        label_2->setObjectName("label_2");

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_2);

        lineEdit_parallelCount = new QLineEdit(widget_base);
        lineEdit_parallelCount->setObjectName("lineEdit_parallelCount");
        lineEdit_parallelCount->setMinimumSize(QSize(0, 40));
        lineEdit_parallelCount->setMaximumSize(QSize(16777215, 40));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, lineEdit_parallelCount);

        label_16 = new QLabel(widget_base);
        label_16->setObjectName("label_16");

        formLayout_3->setWidget(9, QFormLayout::LabelRole, label_16);

        lineEdit_dingTalkPhones = new QLineEdit(widget_base);
        lineEdit_dingTalkPhones->setObjectName("lineEdit_dingTalkPhones");
        lineEdit_dingTalkPhones->setMinimumSize(QSize(0, 40));
        lineEdit_dingTalkPhones->setMaximumSize(QSize(16777215, 40));

        formLayout_3->setWidget(9, QFormLayout::FieldRole, lineEdit_dingTalkPhones);


        verticalLayout_9->addLayout(formLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer);


        verticalLayout_6->addWidget(widget_base);


        verticalLayout_3->addWidget(groupBox_base);

        stackedWidget->addWidget(page_base);
        page_other = new QWidget();
        page_other->setObjectName("page_other");
        sizePolicy.setHeightForWidth(page_other->sizePolicy().hasHeightForWidth());
        page_other->setSizePolicy(sizePolicy);
        verticalLayout_7 = new QVBoxLayout(page_other);
        verticalLayout_7->setObjectName("verticalLayout_7");
        groupBox_other = new QGroupBox(page_other);
        groupBox_other->setObjectName("groupBox_other");
        sizePolicy.setHeightForWidth(groupBox_other->sizePolicy().hasHeightForWidth());
        groupBox_other->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(groupBox_other);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(20, 20, 20, 20);
        widget_other = new QWidget(groupBox_other);
        widget_other->setObjectName("widget_other");
        sizePolicy.setHeightForWidth(widget_other->sizePolicy().hasHeightForWidth());
        widget_other->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(widget_other);
        verticalLayout_5->setObjectName("verticalLayout_5");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(widget_other);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_settingName = new QLineEdit(widget_other);
        lineEdit_settingName->setObjectName("lineEdit_settingName");
        lineEdit_settingName->setMinimumSize(QSize(0, 40));
        lineEdit_settingName->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_settingName);

        label_4 = new QLabel(widget_other);
        label_4->setObjectName("label_4");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lineEdit_width = new QLineEdit(widget_other);
        lineEdit_width->setObjectName("lineEdit_width");
        lineEdit_width->setMinimumSize(QSize(0, 40));
        lineEdit_width->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_4->addWidget(lineEdit_width);

        lineEdit_height = new QLineEdit(widget_other);
        lineEdit_height->setObjectName("lineEdit_height");
        lineEdit_height->setMinimumSize(QSize(0, 40));
        lineEdit_height->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_4->addWidget(lineEdit_height);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_4);

        label_9 = new QLabel(widget_other);
        label_9->setObjectName("label_9");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lineEdit_x = new QLineEdit(widget_other);
        lineEdit_x->setObjectName("lineEdit_x");
        lineEdit_x->setMinimumSize(QSize(0, 40));
        lineEdit_x->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_5->addWidget(lineEdit_x);

        lineEdit_y = new QLineEdit(widget_other);
        lineEdit_y->setObjectName("lineEdit_y");
        lineEdit_y->setMinimumSize(QSize(0, 40));
        lineEdit_y->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_5->addWidget(lineEdit_y);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_5);

        label_13 = new QLabel(widget_other);
        label_13->setObjectName("label_13");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_13);

        lineEdit_sideLength = new QLineEdit(widget_other);
        lineEdit_sideLength->setObjectName("lineEdit_sideLength");
        lineEdit_sideLength->setMinimumSize(QSize(0, 40));
        lineEdit_sideLength->setMaximumSize(QSize(16777215, 40));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_sideLength);

        label_14 = new QLabel(widget_other);
        label_14->setObjectName("label_14");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        lineEdit_labelWidth = new QLineEdit(widget_other);
        lineEdit_labelWidth->setObjectName("lineEdit_labelWidth");
        lineEdit_labelWidth->setMinimumSize(QSize(0, 40));
        lineEdit_labelWidth->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_12->addWidget(lineEdit_labelWidth);

        lineEdit_labelHeight = new QLineEdit(widget_other);
        lineEdit_labelHeight->setObjectName("lineEdit_labelHeight");
        lineEdit_labelHeight->setMinimumSize(QSize(0, 40));
        lineEdit_labelHeight->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_12->addWidget(lineEdit_labelHeight);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_12);

        label_15 = new QLabel(widget_other);
        label_15->setObjectName("label_15");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_15);

        lineEdit_blockNum = new QLineEdit(widget_other);
        lineEdit_blockNum->setObjectName("lineEdit_blockNum");
        lineEdit_blockNum->setMinimumSize(QSize(0, 40));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_blockNum);


        verticalLayout_5->addLayout(formLayout);


        verticalLayout_4->addWidget(widget_other);


        verticalLayout_7->addWidget(groupBox_other);

        stackedWidget->addWidget(page_other);

        horizontalLayout_2->addWidget(stackedWidget);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 7);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setMinimumSize(QSize(80, 40));
        pushButton_add->setMaximumSize(QSize(80, 40));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/add_task.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_add->setIcon(icon2);

        horizontalLayout_3->addWidget(pushButton_add);

        pushButton_ok = new QPushButton(centralwidget);
        pushButton_ok->setObjectName("pushButton_ok");
        sizePolicy1.setHeightForWidth(pushButton_ok->sizePolicy().hasHeightForWidth());
        pushButton_ok->setSizePolicy(sizePolicy1);
        pushButton_ok->setMinimumSize(QSize(80, 40));
        pushButton_ok->setMaximumSize(QSize(80, 40));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icon/ok.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_ok->setIcon(icon3);
        pushButton_ok->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(pushButton_ok);

        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName("pushButton_clear");
        sizePolicy1.setHeightForWidth(pushButton_clear->sizePolicy().hasHeightForWidth());
        pushButton_clear->setSizePolicy(sizePolicy1);
        pushButton_clear->setMinimumSize(QSize(80, 40));
        pushButton_clear->setMaximumSize(QSize(80, 40));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icon/clear_task.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_clear->setIcon(icon4);
        pushButton_clear->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(pushButton_clear);

        pushButton_noOk = new QPushButton(centralwidget);
        pushButton_noOk->setObjectName("pushButton_noOk");
        sizePolicy1.setHeightForWidth(pushButton_noOk->sizePolicy().hasHeightForWidth());
        pushButton_noOk->setSizePolicy(sizePolicy1);
        pushButton_noOk->setMinimumSize(QSize(80, 40));
        pushButton_noOk->setMaximumSize(QSize(80, 40));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icon/no_ok.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_noOk->setIcon(icon5);
        pushButton_noOk->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(pushButton_noOk);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_8->addLayout(verticalLayout_2);

        SettingWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SettingWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1149, 26));
        SettingWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SettingWindow);
        statusbar->setObjectName("statusbar");
        SettingWindow->setStatusBar(statusbar);

        retranslateUi(SettingWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(statustip)
        SettingWindow->setStatusTip(QCoreApplication::translate("SettingWindow", "\345\215\225\344\275\215: mm", nullptr));
#endif // QT_CONFIG(statustip)
        lineEdit_search->setPlaceholderText(QCoreApplication::translate("SettingWindow", "\350\257\267\350\276\223\345\205\245\351\205\215\347\275\256\345\220\215", nullptr));
        pushButton_search->setText(QCoreApplication::translate("SettingWindow", "\346\220\234\347\264\242", nullptr));
        groupBox_base->setTitle(QCoreApplication::translate("SettingWindow", "\345\237\272\347\241\200\351\205\215\347\275\256", nullptr));
        label_10->setText(QCoreApplication::translate("SettingWindow", "\346\217\220\345\217\226\346\226\207\344\273\266\350\267\257\345\276\204:", nullptr));
        pushButton_extractFile->setText(QCoreApplication::translate("SettingWindow", "...", nullptr));
        label_5->setText(QCoreApplication::translate("SettingWindow", "\347\247\215\345\255\220\344\277\235\345\255\230\350\267\257\345\276\204:", nullptr));
        pushButton_dir_seedPath->setText(QCoreApplication::translate("SettingWindow", "...", nullptr));
        label_6->setText(QCoreApplication::translate("SettingWindow", "\345\244\261\350\264\245\345\233\276\347\211\207\344\277\235\345\255\230\350\267\257\345\276\204:", nullptr));
        pushButton_dir_failedImage->setText(QCoreApplication::translate("SettingWindow", "...", nullptr));
        label_7->setText(QCoreApplication::translate("SettingWindow", "\346\230\257\345\220\246\344\270\212\344\274\240\346\234\215\345\212\241\345\231\250:", nullptr));
        checkBox_uploadServer->setText(QString());
        label_3->setText(QCoreApplication::translate("SettingWindow", "\351\222\211\351\222\211\351\200\232\347\237\245\351\223\276\346\216\245:", nullptr));
        label_8->setText(QCoreApplication::translate("SettingWindow", "\346\230\257\345\220\246\351\222\211\351\222\211\346\217\220\351\206\222:", nullptr));
        checkBox_dingTalk->setText(QString());
        label_11->setText(QCoreApplication::translate("SettingWindow", "python\346\211\247\350\241\214\350\267\257\345\276\204:", nullptr));
        pushButton_pythonPath->setText(QCoreApplication::translate("SettingWindow", "...", nullptr));
        label_12->setText(QCoreApplication::translate("SettingWindow", "python\350\204\232\346\234\254\350\267\257\345\276\204:", nullptr));
        pushButton_pythonScript->setText(QCoreApplication::translate("SettingWindow", "...", nullptr));
        label_2->setText(QCoreApplication::translate("SettingWindow", "GPU\345\271\266\350\241\214\346\225\260:", nullptr));
        label_16->setText(QCoreApplication::translate("SettingWindow", "\351\222\211\351\222\211\351\200\232\347\237\245\346\211\213\346\234\272\345\217\267:", nullptr));
        groupBox_other->setTitle(QCoreApplication::translate("SettingWindow", "\346\217\220\345\217\226\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("SettingWindow", "\351\205\215\347\275\256\345\220\215\347\247\260:", nullptr));
        label_4->setText(QCoreApplication::translate("SettingWindow", "\351\225\255\345\260\204\345\214\272\345\237\237\345\256\275\351\253\230:", nullptr));
        lineEdit_width->setPlaceholderText(QCoreApplication::translate("SettingWindow", "\345\256\275", nullptr));
        lineEdit_height->setPlaceholderText(QCoreApplication::translate("SettingWindow", "\351\253\230", nullptr));
        label_9->setText(QCoreApplication::translate("SettingWindow", "\344\272\214\347\273\264\347\240\201\345\267\246\344\270\212\350\247\222\345\235\220\346\240\207:", nullptr));
        lineEdit_x->setPlaceholderText(QCoreApplication::translate("SettingWindow", "X\345\235\220\346\240\207", nullptr));
        lineEdit_y->setPlaceholderText(QCoreApplication::translate("SettingWindow", "Y\345\235\220\346\240\207", nullptr));
        label_13->setText(QCoreApplication::translate("SettingWindow", "\344\272\214\347\273\264\347\240\201\350\276\271\351\225\277:", nullptr));
        lineEdit_sideLength->setPlaceholderText(QCoreApplication::translate("SettingWindow", "\344\272\214\347\273\264\347\240\201\350\276\271\351\225\277", nullptr));
        label_14->setText(QCoreApplication::translate("SettingWindow", "\346\225\264\344\270\252\346\240\207\347\255\276\345\256\275\351\253\230:", nullptr));
        lineEdit_labelWidth->setPlaceholderText(QCoreApplication::translate("SettingWindow", "\345\256\275", nullptr));
        lineEdit_labelHeight->setPlaceholderText(QCoreApplication::translate("SettingWindow", "\351\253\230", nullptr));
        label_15->setText(QCoreApplication::translate("SettingWindow", "\347\262\211\345\235\227\346\225\260\351\207\217:", nullptr));
        lineEdit_blockNum->setPlaceholderText(QCoreApplication::translate("SettingWindow", "10", nullptr));
        pushButton_add->setText(QCoreApplication::translate("SettingWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("SettingWindow", "\347\241\256\345\256\232", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("SettingWindow", "\346\270\205\351\231\244", nullptr));
        pushButton_noOk->setText(QCoreApplication::translate("SettingWindow", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
