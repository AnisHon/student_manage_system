/********************************************************************************
** Form generated from reading UI file 'studentwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWIDGET_H
#define UI_STUDENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout;
    QComboBox *searchMethod;
    QLineEdit *searchEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitBtn;
    QPushButton *pushButton;
    QPushButton *deleteStudent;
    QPushButton *addStudent;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *pictureLabel;
    QPushButton *pushButton_2;
    QFormLayout *formLayout_3;
    QLabel *Label_7;
    QLineEdit *studentIdInput;
    QLabel *Label_8;
    QLineEdit *nameInput;
    QLabel *Label_9;
    QComboBox *genderBox;
    QLabel *age_2;
    QSpinBox *ageBox;
    QLabel *Label_10;
    QLineEdit *addressInput;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *StudentWidget)
    {
        if (StudentWidget->objectName().isEmpty())
            StudentWidget->setObjectName("StudentWidget");
        StudentWidget->resize(792, 583);
        StudentWidget->setStyleSheet(QString::fromUtf8("\n"
"StudentWidget QLineEdit {\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(StudentWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(12, 12, 12, 12);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(12, 0, 12, 12);
        groupBox = new QGroupBox(StudentWidget);
        groupBox->setObjectName("groupBox");
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        formLayout->setLabelAlignment(Qt::AlignCenter);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setVerticalSpacing(0);
        searchMethod = new QComboBox(groupBox);
        searchMethod->addItem(QString());
        searchMethod->addItem(QString());
        searchMethod->setObjectName("searchMethod");

        formLayout->setWidget(0, QFormLayout::LabelRole, searchMethod);

        searchEdit = new QLineEdit(groupBox);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setMinimumSize(QSize(280, 0));

        formLayout->setWidget(0, QFormLayout::FieldRole, searchEdit);


        verticalLayout_4->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        submitBtn = new QPushButton(groupBox);
        submitBtn->setObjectName("submitBtn");
        submitBtn->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(submitBtn);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        deleteStudent = new QPushButton(groupBox);
        deleteStudent->setObjectName("deleteStudent");
        deleteStudent->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(deleteStudent);

        addStudent = new QPushButton(groupBox);
        addStudent->setObjectName("addStudent");
        addStudent->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(addStudent);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox);

        tableView = new QTableView(StudentWidget);
        tableView->setObjectName("tableView");
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(tableView);


        horizontalLayout_2->addLayout(verticalLayout_2);

        groupBox_3 = new QGroupBox(StudentWidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setMaximumSize(QSize(230, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        pictureLabel = new QLabel(groupBox_3);
        pictureLabel->setObjectName("pictureLabel");
        pictureLabel->setMinimumSize(QSize(200, 200));

        verticalLayout_3->addWidget(pictureLabel);

        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_3->addWidget(pushButton_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        Label_7 = new QLabel(groupBox_3);
        Label_7->setObjectName("Label_7");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, Label_7);

        studentIdInput = new QLineEdit(groupBox_3);
        studentIdInput->setObjectName("studentIdInput");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, studentIdInput);

        Label_8 = new QLabel(groupBox_3);
        Label_8->setObjectName("Label_8");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, Label_8);

        nameInput = new QLineEdit(groupBox_3);
        nameInput->setObjectName("nameInput");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, nameInput);

        Label_9 = new QLabel(groupBox_3);
        Label_9->setObjectName("Label_9");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, Label_9);

        genderBox = new QComboBox(groupBox_3);
        genderBox->addItem(QString());
        genderBox->addItem(QString());
        genderBox->setObjectName("genderBox");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, genderBox);

        age_2 = new QLabel(groupBox_3);
        age_2->setObjectName("age_2");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, age_2);

        ageBox = new QSpinBox(groupBox_3);
        ageBox->setObjectName("ageBox");
        ageBox->setMaximum(100);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, ageBox);

        Label_10 = new QLabel(groupBox_3);
        Label_10->setObjectName("Label_10");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, Label_10);

        addressInput = new QLineEdit(groupBox_3);
        addressInput->setObjectName("addressInput");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, addressInput);


        verticalLayout_3->addLayout(formLayout_3);

        label = new QLabel(groupBox_3);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(groupBox_3);


        retranslateUi(StudentWidget);

        searchMethod->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StudentWidget);
    } // setupUi

    void retranslateUi(QWidget *StudentWidget)
    {
        StudentWidget->setWindowTitle(QCoreApplication::translate("StudentWidget", "Form", nullptr));
        groupBox->setTitle(QString());
        searchMethod->setItemText(0, QCoreApplication::translate("StudentWidget", "\346\220\234\347\264\242\345\247\223\345\220\215", nullptr));
        searchMethod->setItemText(1, QCoreApplication::translate("StudentWidget", "\346\220\234\347\264\242\345\255\246\345\217\267", nullptr));

        submitBtn->setText(QCoreApplication::translate("StudentWidget", "\346\217\220\344\272\244\346\233\264\346\224\271", nullptr));
        pushButton->setText(QCoreApplication::translate("StudentWidget", "\345\217\226\346\266\210\346\233\264\346\224\271", nullptr));
        deleteStudent->setText(QCoreApplication::translate("StudentWidget", "\345\210\240\351\231\244\345\255\246\347\224\237", nullptr));
        addStudent->setText(QCoreApplication::translate("StudentWidget", "\346\267\273\345\212\240\345\255\246\347\224\237", nullptr));
        groupBox_3->setTitle(QString());
        pictureLabel->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("StudentWidget", "\346\233\264\346\215\242\345\244\264\345\203\217", nullptr));
        Label_7->setText(QCoreApplication::translate("StudentWidget", "\345\255\246\347\224\237\345\255\246\345\217\267", nullptr));
#if QT_CONFIG(whatsthis)
        studentIdInput->setWhatsThis(QCoreApplication::translate("StudentWidget", "<html><head/><body><p>\350\257\267\350\260\250\346\205\216\346\233\264\346\224\271\345\255\246\345\217\267</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Label_8->setText(QCoreApplication::translate("StudentWidget", "\345\247\223\345\220\215", nullptr));
        Label_9->setText(QCoreApplication::translate("StudentWidget", "\346\200\247\345\210\253", nullptr));
        genderBox->setItemText(0, QCoreApplication::translate("StudentWidget", "\347\224\267", nullptr));
        genderBox->setItemText(1, QCoreApplication::translate("StudentWidget", "\345\245\263", nullptr));

        age_2->setText(QCoreApplication::translate("StudentWidget", "\345\271\264\351\276\204", nullptr));
        Label_10->setText(QCoreApplication::translate("StudentWidget", "\344\275\217\345\235\200", nullptr));
        label->setText(QCoreApplication::translate("StudentWidget", "<html><head/><body><p><span style=\" font-size:18pt; color:#ff9300;\">\350\257\267\347\273\223\346\235\237\345\220\216\347\202\271\345\207\273\346\217\220\344\272\244</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWidget: public Ui_StudentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWIDGET_H
