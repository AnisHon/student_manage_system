/********************************************************************************
** Form generated from reading UI file 'scorewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREWIDGET_H
#define UI_SCOREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScoreWidget
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableView *tableView;

    void setupUi(QWidget *ScoreWidget)
    {
        if (ScoreWidget->objectName().isEmpty())
            ScoreWidget->setObjectName("ScoreWidget");
        ScoreWidget->resize(863, 560);
        verticalLayout_3 = new QVBoxLayout(ScoreWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(ScoreWidget);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(100, -1, 100, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);

        tableView = new QTableView(ScoreWidget);
        tableView->setObjectName("tableView");

        verticalLayout_3->addWidget(tableView);


        retranslateUi(ScoreWidget);

        QMetaObject::connectSlotsByName(ScoreWidget);
    } // setupUi

    void retranslateUi(QWidget *ScoreWidget)
    {
        ScoreWidget->setWindowTitle(QCoreApplication::translate("ScoreWidget", "Form", nullptr));
        groupBox->setTitle(QString());
        comboBox->setItemText(0, QCoreApplication::translate("ScoreWidget", "\346\220\234\347\264\242\345\220\215\345\255\227", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ScoreWidget", "\346\220\234\347\264\242\345\255\246\345\217\267", nullptr));

        pushButton_2->setText(QCoreApplication::translate("ScoreWidget", "\346\267\273\345\212\240\345\210\206\346\225\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ScoreWidget", "\345\210\240\351\231\244\345\210\206\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreWidget: public Ui_ScoreWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWIDGET_H
