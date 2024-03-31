/********************************************************************************
** Form generated from reading UI file 'statisticwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICWIDGET_H
#define UI_STATISTICWIDGET_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QChartView *line;
    QChartView *pie;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QChartView *bar;
    QGroupBox *groupbox_;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QLabel *Label;
    QLabel *label;
    QComboBox *ComboBox;
    QLabel *label_2;
    QListWidget *listWidget;

    void setupUi(QWidget *StatisticWidget)
    {
        if (StatisticWidget->objectName().isEmpty())
            StatisticWidget->setObjectName("StatisticWidget");
        StatisticWidget->resize(840, 567);
        StatisticWidget->setStyleSheet(QString::fromUtf8("StatisticWidget QGroupBox {\n"
"	backgroud-color: transparent;\n"
"}\n"
"StatisticWidget>QGroupBox>QChartView {\n"
"	background-color: transparent;\n"
"}"));
        verticalLayout = new QVBoxLayout(StatisticWidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(StatisticWidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(3);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        line = new QChartView(groupBox);
        line->setObjectName("line");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setMinimumSize(QSize(300, 200));

        horizontalLayout->addWidget(line);

        pie = new QChartView(groupBox);
        pie->setObjectName("pie");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(3);
        sizePolicy2.setVerticalStretch(2);
        sizePolicy2.setHeightForWidth(pie->sizePolicy().hasHeightForWidth());
        pie->setSizePolicy(sizePolicy2);
        pie->setMinimumSize(QSize(500, 200));

        horizontalLayout->addWidget(pie);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(StatisticWidget);
        groupBox_2->setObjectName("groupBox_2");
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        bar = new QChartView(groupBox_2);
        bar->setObjectName("bar");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(4);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bar->sizePolicy().hasHeightForWidth());
        bar->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(bar);

        groupbox_ = new QGroupBox(groupBox_2);
        groupbox_->setObjectName("groupbox_");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(2);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupbox_->sizePolicy().hasHeightForWidth());
        groupbox_->setSizePolicy(sizePolicy4);
        verticalLayout_2 = new QVBoxLayout(groupbox_);
        verticalLayout_2->setObjectName("verticalLayout_2");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        Label = new QLabel(groupbox_);
        Label->setObjectName("Label");

        formLayout->setWidget(2, QFormLayout::LabelRole, Label);

        label = new QLabel(groupbox_);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        ComboBox = new QComboBox(groupbox_);
        ComboBox->setObjectName("ComboBox");

        formLayout->setWidget(2, QFormLayout::FieldRole, ComboBox);

        label_2 = new QLabel(groupbox_);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::SpanningRole, label_2);

        listWidget = new QListWidget(groupbox_);
        listWidget->setObjectName("listWidget");

        formLayout->setWidget(3, QFormLayout::SpanningRole, listWidget);


        verticalLayout_2->addLayout(formLayout);


        horizontalLayout_2->addWidget(groupbox_);


        verticalLayout->addWidget(groupBox_2);


        retranslateUi(StatisticWidget);

        QMetaObject::connectSlotsByName(StatisticWidget);
    } // setupUi

    void retranslateUi(QWidget *StatisticWidget)
    {
        StatisticWidget->setWindowTitle(QCoreApplication::translate("StatisticWidget", "Form", nullptr));
        groupBox_2->setTitle(QString());
        Label->setText(QCoreApplication::translate("StatisticWidget", "\347\247\221\347\233\256", nullptr));
        label->setText(QCoreApplication::translate("StatisticWidget", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">\345\271\263\345\235\207\345\210\206\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("StatisticWidget", "\346\200\273\344\272\272\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticWidget: public Ui_StatisticWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICWIDGET_H
