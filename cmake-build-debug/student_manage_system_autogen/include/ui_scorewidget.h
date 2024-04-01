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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QGridLayout *gridLayout_2;
    QPushButton *deleteBtn;
    QPushButton *addBtn;
    QPushButton *refreshBtn;
    QPushButton *changeBtn;
    QFormLayout *formLayout_2;
    QLabel *Label;
    QComboBox *sortMethod;
    QLabel *Label_2;
    QComboBox *sortColumn;
    QTableView *tableView;

    void setupUi(QWidget *ScoreWidget)
    {
        if (ScoreWidget->objectName().isEmpty())
            ScoreWidget->setObjectName("ScoreWidget");
        ScoreWidget->resize(863, 560);
        ScoreWidget->setStyleSheet(QString::fromUtf8(""));
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

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        deleteBtn = new QPushButton(groupBox);
        deleteBtn->setObjectName("deleteBtn");

        gridLayout_2->addWidget(deleteBtn, 1, 0, 1, 1);

        addBtn = new QPushButton(groupBox);
        addBtn->setObjectName("addBtn");

        gridLayout_2->addWidget(addBtn, 0, 0, 1, 1);

        refreshBtn = new QPushButton(groupBox);
        refreshBtn->setObjectName("refreshBtn");

        gridLayout_2->addWidget(refreshBtn, 1, 1, 1, 1);

        changeBtn = new QPushButton(groupBox);
        changeBtn->setObjectName("changeBtn");

        gridLayout_2->addWidget(changeBtn, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, -1, -1, -1);
        Label = new QLabel(groupBox);
        Label->setObjectName("Label");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, Label);

        sortMethod = new QComboBox(groupBox);
        sortMethod->addItem(QString());
        sortMethod->addItem(QString());
        sortMethod->setObjectName("sortMethod");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sortMethod->sizePolicy().hasHeightForWidth());
        sortMethod->setSizePolicy(sizePolicy);
        sortMethod->setMaximumSize(QSize(100, 16777215));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sortMethod);

        Label_2 = new QLabel(groupBox);
        Label_2->setObjectName("Label_2");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, Label_2);

        sortColumn = new QComboBox(groupBox);
        sortColumn->setObjectName("sortColumn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sortColumn->sizePolicy().hasHeightForWidth());
        sortColumn->setSizePolicy(sizePolicy1);
        sortColumn->setMaximumSize(QSize(100, 16777215));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, sortColumn);


        horizontalLayout->addLayout(formLayout_2);


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

        deleteBtn->setText(QCoreApplication::translate("ScoreWidget", "\345\210\240\351\231\244\345\210\206\346\225\260", nullptr));
        addBtn->setText(QCoreApplication::translate("ScoreWidget", "\346\267\273\345\212\240\345\210\206\346\225\260", nullptr));
        refreshBtn->setText(QCoreApplication::translate("ScoreWidget", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        changeBtn->setText(QCoreApplication::translate("ScoreWidget", "\344\277\256\346\224\271\345\210\206\346\225\260", nullptr));
        Label->setText(QCoreApplication::translate("ScoreWidget", "\346\216\222\345\272\217\346\226\271\345\274\217", nullptr));
        sortMethod->setItemText(0, QCoreApplication::translate("ScoreWidget", "\345\215\207\345\272\217", nullptr));
        sortMethod->setItemText(1, QCoreApplication::translate("ScoreWidget", "\351\231\215\345\272\217", nullptr));

        Label_2->setText(QCoreApplication::translate("ScoreWidget", "\346\216\222\345\272\217\345\210\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScoreWidget: public Ui_ScoreWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREWIDGET_H
