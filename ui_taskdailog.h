/********************************************************************************
** Form generated from reading UI file 'taskdailog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDAILOG_H
#define UI_TASKDAILOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskDailog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBox_setting;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_extractPath;
    QPushButton *pushButton_extractPath;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_close;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *TaskDailog)
    {
        if (TaskDailog->objectName().isEmpty())
            TaskDailog->setObjectName("TaskDailog");
        TaskDailog->resize(534, 337);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskDailog->sizePolicy().hasHeightForWidth());
        TaskDailog->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        TaskDailog->setFont(font);
        verticalLayout = new QVBoxLayout(TaskDailog);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget = new QWidget(TaskDailog);
        widget->setObjectName("widget");
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label = new QLabel(widget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBox_setting = new QComboBox(widget);
        comboBox_setting->setObjectName("comboBox_setting");
        comboBox_setting->setMinimumSize(QSize(0, 40));
        comboBox_setting->setMaximumSize(QSize(16777215, 40));
        comboBox_setting->setEditable(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_setting);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_extractPath = new QLineEdit(widget);
        lineEdit_extractPath->setObjectName("lineEdit_extractPath");
        lineEdit_extractPath->setMinimumSize(QSize(0, 40));
        lineEdit_extractPath->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(lineEdit_extractPath);

        pushButton_extractPath = new QPushButton(widget);
        pushButton_extractPath->setObjectName("pushButton_extractPath");
        pushButton_extractPath->setMinimumSize(QSize(80, 40));
        pushButton_extractPath->setMaximumSize(QSize(80, 40));

        horizontalLayout->addWidget(pushButton_extractPath);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);


        horizontalLayout_3->addLayout(formLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 8);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_ok = new QPushButton(TaskDailog);
        pushButton_ok->setObjectName("pushButton_ok");
        pushButton_ok->setMinimumSize(QSize(80, 40));
        pushButton_ok->setMaximumSize(QSize(80, 40));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/ok.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ok->setIcon(icon);
        pushButton_ok->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_ok);

        pushButton_close = new QPushButton(TaskDailog);
        pushButton_close->setObjectName("pushButton_close");
        pushButton_close->setMinimumSize(QSize(80, 40));
        pushButton_close->setMaximumSize(QSize(80, 40));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/no_ok.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_close->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_close);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_2->setStretch(0, 7);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 8);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(TaskDailog);

        comboBox_setting->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(TaskDailog);
    } // setupUi

    void retranslateUi(QDialog *TaskDailog)
    {
        TaskDailog->setWindowTitle(QCoreApplication::translate("TaskDailog", "\346\267\273\345\212\240\344\273\273\345\212\241", nullptr));
        label->setText(QCoreApplication::translate("TaskDailog", "\351\200\211\346\213\251\351\205\215\347\275\256:", nullptr));
        label_2->setText(QCoreApplication::translate("TaskDailog", "\351\200\211\346\213\251\346\217\220\345\217\226\350\267\257\345\276\204:", nullptr));
        pushButton_extractPath->setText(QCoreApplication::translate("TaskDailog", "...", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("TaskDailog", "\347\241\256\345\256\232", nullptr));
        pushButton_close->setText(QCoreApplication::translate("TaskDailog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDailog: public Ui_TaskDailog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDAILOG_H
