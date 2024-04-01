/********************************************************************************
** Form generated from reading UI file 'sidebar.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEBAR_H
#define UI_SIDEBAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideBar
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *bar;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *indexBtn;
    QPushButton *studentBtn;
    QPushButton *scoreBtn;
    QPushButton *statisticBtn;
    QSpacerItem *verticalSpacer;
    QStackedWidget *conetent;
    QWidget *page_3;
    QWidget *page_4;

    void setupUi(QWidget *SideBar)
    {
        if (SideBar->objectName().isEmpty())
            SideBar->setObjectName("SideBar");
        SideBar->resize(774, 600);
        SideBar->setStyleSheet(QString::fromUtf8("#SIdeBar {\n"
"	background-color: transparent;\n"
"	\n"
"}\n"
"#content {\n"
"	background-color: #ECECEB;\n"
"}"));
        horizontalLayout = new QHBoxLayout(SideBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        bar = new QWidget(SideBar);
        bar->setObjectName("bar");
        bar->setMinimumSize(QSize(150, 0));
        bar->setMaximumSize(QSize(150, 16777215));
        bar->setStyleSheet(QString::fromUtf8("#bar {\n"
"	background-color: rgba(224, 224, 222, 0.95);\n"
"	padding: 40% 0;\n"
"}\n"
"#bar>QPushButton {\n"
"	height: 60px;\n"
"	background-color: transparent;\n"
"	color: #242423;\n"
"	border: None;\n"
"		\n"
"}\n"
"#bar>QPushButton:hover {\n"
"	\n"
"}\n"
"\n"
"#bar>QPushButton:checked {\n"
"	background-color: rgba(60, 131, 247, 0.9);\n"
"}"));
        verticalLayout = new QVBoxLayout(bar);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 100, 0, 100);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        indexBtn = new QPushButton(bar);
        indexBtn->setObjectName("indexBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(indexBtn->sizePolicy().hasHeightForWidth());
        indexBtn->setSizePolicy(sizePolicy);
        indexBtn->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/icon/shouye.png"), QSize(), QIcon::Normal, QIcon::Off);
        indexBtn->setIcon(icon);
        indexBtn->setCheckable(true);
        indexBtn->setChecked(false);
        indexBtn->setAutoDefault(false);
        indexBtn->setFlat(false);

        verticalLayout->addWidget(indexBtn);

        studentBtn = new QPushButton(bar);
        studentBtn->setObjectName("studentBtn");
        sizePolicy.setHeightForWidth(studentBtn->sizePolicy().hasHeightForWidth());
        studentBtn->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/icon/xuesheng.png"), QSize(), QIcon::Normal, QIcon::Off);
        studentBtn->setIcon(icon1);
        studentBtn->setCheckable(true);

        verticalLayout->addWidget(studentBtn);

        scoreBtn = new QPushButton(bar);
        scoreBtn->setObjectName("scoreBtn");
        sizePolicy.setHeightForWidth(scoreBtn->sizePolicy().hasHeightForWidth());
        scoreBtn->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/icon/chengji.png"), QSize(), QIcon::Normal, QIcon::Off);
        scoreBtn->setIcon(icon2);
        scoreBtn->setCheckable(true);

        verticalLayout->addWidget(scoreBtn);

        statisticBtn = new QPushButton(bar);
        statisticBtn->setObjectName("statisticBtn");
        sizePolicy.setHeightForWidth(statisticBtn->sizePolicy().hasHeightForWidth());
        statisticBtn->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/icon/tubiao-zhexiantu.png"), QSize(), QIcon::Normal, QIcon::Off);
        statisticBtn->setIcon(icon3);
        statisticBtn->setCheckable(true);

        verticalLayout->addWidget(statisticBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(bar);

        conetent = new QStackedWidget(SideBar);
        conetent->setObjectName("conetent");
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush5(QColor(0, 0, 0, 127));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush6(QColor(127, 127, 127, 127));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        conetent->setPalette(palette);
        conetent->setFrameShape(QFrame::NoFrame);
        conetent->setFrameShadow(QFrame::Plain);
        conetent->setLineWidth(0);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        conetent->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        conetent->addWidget(page_4);

        horizontalLayout->addWidget(conetent);


        retranslateUi(SideBar);

        indexBtn->setDefault(false);
        conetent->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SideBar);
    } // setupUi

    void retranslateUi(QWidget *SideBar)
    {
        SideBar->setWindowTitle(QCoreApplication::translate("SideBar", "Form", nullptr));
        indexBtn->setText(QCoreApplication::translate("SideBar", "\351\246\226\351\241\265", nullptr));
        studentBtn->setText(QCoreApplication::translate("SideBar", "\345\255\246\347\224\237\347\256\241\347\220\206", nullptr));
        scoreBtn->setText(QCoreApplication::translate("SideBar", "\346\210\220\347\273\251\347\256\241\347\220\206", nullptr));
        statisticBtn->setText(QCoreApplication::translate("SideBar", "\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideBar: public Ui_SideBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEBAR_H
