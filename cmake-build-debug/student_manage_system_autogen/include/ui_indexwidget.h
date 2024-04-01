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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndexWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *IndexWidget)
    {
        if (IndexWidget->objectName().isEmpty())
            IndexWidget->setObjectName("IndexWidget");
        IndexWidget->resize(400, 300);
        IndexWidget->setStyleSheet(QString::fromUtf8("IndexWidget {\n"
"	background-color: #ECECEB;\n"
"}"));
        label = new QLabel(IndexWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 100, 58, 16));

        retranslateUi(IndexWidget);

        QMetaObject::connectSlotsByName(IndexWidget);
    } // setupUi

    void retranslateUi(QWidget *IndexWidget)
    {
        IndexWidget->setWindowTitle(QCoreApplication::translate("IndexWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("IndexWidget", "index", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IndexWidget: public Ui_IndexWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXWIDGET_H
