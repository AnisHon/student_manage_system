/********************************************************************************
** Form generated from reading UI file 'indexwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXWIDGET_H
#define UI_INDEXWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "circleprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_IndexWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *portrait;
    QLabel *name;
    QLabel *time;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    CircleProgressBar *cpu;
    CircleProgressBar *mem;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *database;
    QLabel *table;
    QLabel *storeLabel;
    QProgressBar *storeBar;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;

    void setupUi(QWidget *IndexWidget)
    {
        if (IndexWidget->objectName().isEmpty())
            IndexWidget->setObjectName("IndexWidget");
        IndexWidget->resize(984, 589);
        IndexWidget->setStyleSheet(QString::fromUtf8("IndexWidget {\n"
"	background-color: #ECECEB;\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(IndexWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(-1, 17, -1, -1);
        groupBox = new QGroupBox(IndexWidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        portrait = new QLabel(groupBox);
        portrait->setObjectName("portrait");
        portrait->setMinimumSize(QSize(0, 100));
        portrait->setAutoFillBackground(false);
        portrait->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(portrait);

        name = new QLabel(groupBox);
        name->setObjectName("name");
        name->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name);

        time = new QLabel(groupBox);
        time->setObjectName("time");
        time->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(time);


        verticalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(IndexWidget);
        groupBox_3->setObjectName("groupBox_3");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(24);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(48, 48, 48, 48);
        cpu = new CircleProgressBar(groupBox_3);
        cpu->setObjectName("cpu");

        horizontalLayout->addWidget(cpu);

        mem = new CircleProgressBar(groupBox_3);
        mem->setObjectName("mem");

        horizontalLayout->addWidget(mem);


        verticalLayout_4->addWidget(groupBox_3);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox_4 = new QGroupBox(IndexWidget);
        groupBox_4->setObjectName("groupBox_4");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        groupBox_4->setMinimumSize(QSize(100, 150));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(12, 24, -1, -1);
        database = new QLabel(groupBox_4);
        database->setObjectName("database");

        verticalLayout_3->addWidget(database);

        table = new QLabel(groupBox_4);
        table->setObjectName("table");

        verticalLayout_3->addWidget(table);

        storeLabel = new QLabel(groupBox_4);
        storeLabel->setObjectName("storeLabel");

        verticalLayout_3->addWidget(storeLabel);

        storeBar = new QProgressBar(groupBox_4);
        storeBar->setObjectName("storeBar");
        storeBar->setValue(24);

        verticalLayout_3->addWidget(storeBar);


        verticalLayout_5->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(IndexWidget);
        groupBox_2->setObjectName("groupBox_2");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(100, 0));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 24, 0, 0);
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName("tableView");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy4);
        tableView->setMinimumSize(QSize(100, 100));
        tableView->setMaximumSize(QSize(99999, 9999999));
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setDefaultSectionSize(21);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(24);

        verticalLayout->addWidget(tableView);


        verticalLayout_5->addWidget(groupBox_2);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalLayout_2->setStretch(0, 10);
        horizontalLayout_2->setStretch(1, 3);

        retranslateUi(IndexWidget);

        QMetaObject::connectSlotsByName(IndexWidget);
    } // setupUi

    void retranslateUi(QWidget *IndexWidget)
    {
        IndexWidget->setWindowTitle(QCoreApplication::translate("IndexWidget", "Form", nullptr));
        groupBox->setTitle(QString());
        portrait->setText(QString());
        name->setText(QCoreApplication::translate("IndexWidget", "\344\275\240\345\245\275", nullptr));
        time->setText(QCoreApplication::translate("IndexWidget", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232123", nullptr));
        groupBox_3->setTitle(QString());
        groupBox_4->setTitle(QCoreApplication::translate("IndexWidget", "\346\225\260\346\215\256\345\272\223\347\212\266\346\200\201", nullptr));
        database->setText(QCoreApplication::translate("IndexWidget", "\346\225\260\346\215\256\345\272\223\357\274\232", nullptr));
        table->setText(QCoreApplication::translate("IndexWidget", "\345\272\223\345\220\215\347\247\260", nullptr));
        storeLabel->setText(QCoreApplication::translate("IndexWidget", "\345\255\230\345\202\250\350\203\275\345\212\233", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("IndexWidget", "\350\257\276\347\250\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexWidget: public Ui_IndexWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXWIDGET_H
