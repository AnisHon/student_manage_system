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
#include <QtGui/QAction>
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
    QAction *inputAction;
    QAction *outputAction;
    QAction *changeAction;
    QAction *refreshAction;
    QAction *outputAllAction;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_2;
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
        inputAction = new QAction(ScoreWidget);
        inputAction->setObjectName("inputAction");
        inputAction->setMenuRole(QAction::NoRole);
        outputAction = new QAction(ScoreWidget);
        outputAction->setObjectName("outputAction");
        outputAction->setMenuRole(QAction::NoRole);
        changeAction = new QAction(ScoreWidget);
        changeAction->setObjectName("changeAction");
        changeAction->setMenuRole(QAction::NoRole);
        refreshAction = new QAction(ScoreWidget);
        refreshAction->setObjectName("refreshAction");
        refreshAction->setMenuRole(QAction::NoRole);
        outputAllAction = new QAction(ScoreWidget);
        outputAllAction->setObjectName("outputAllAction");
        outputAllAction->setMenuRole(QAction::NoRole);
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
        refreshBtn = new QPushButton(groupBox);
        refreshBtn->setObjectName("refreshBtn");

        gridLayout_2->addWidget(refreshBtn, 1, 0, 1, 1);

        changeBtn = new QPushButton(groupBox);
        changeBtn->setObjectName("changeBtn");

        gridLayout_2->addWidget(changeBtn, 0, 0, 1, 1);


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
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(tableView);


        retranslateUi(ScoreWidget);
        QObject::connect(changeAction, &QAction::triggered, changeBtn, qOverload<>(&QPushButton::click));
        QObject::connect(refreshAction, &QAction::triggered, refreshBtn, qOverload<>(&QPushButton::click));

        QMetaObject::connectSlotsByName(ScoreWidget);
    } // setupUi

    void retranslateUi(QWidget *ScoreWidget)
    {
        ScoreWidget->setWindowTitle(QCoreApplication::translate("ScoreWidget", "Form", nullptr));
        inputAction->setText(QCoreApplication::translate("ScoreWidget", "\345\257\274\345\205\245", nullptr));
        outputAction->setText(QCoreApplication::translate("ScoreWidget", "\345\257\274\345\207\272\345\275\223\345\211\215\350\247\206\345\233\276", nullptr));
        changeAction->setText(QCoreApplication::translate("ScoreWidget", "\344\277\256\346\224\271\345\210\206\346\225\260", nullptr));
        refreshAction->setText(QCoreApplication::translate("ScoreWidget", "\345\210\267\346\226\260", nullptr));
        outputAllAction->setText(QCoreApplication::translate("ScoreWidget", "\345\257\274\345\207\272\346\225\260\346\215\256\345\272\223", nullptr));
        groupBox->setTitle(QString());
        comboBox->setItemText(0, QCoreApplication::translate("ScoreWidget", "\346\220\234\347\264\242\345\220\215\345\255\227", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ScoreWidget", "\346\220\234\347\264\242\345\255\246\345\217\267", nullptr));

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
