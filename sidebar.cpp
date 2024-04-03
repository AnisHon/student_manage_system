#include "sidebar.h"
#include "ui_sidebar.h"
#include <QPalette>

SideBar::SideBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SideBar)
{

    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("db_qt01");
    db.setUserName("anishan");
    db.setPassword("Han123456");
    qDebug() << db.open();


    pointers = {ui->indexBtn, ui->scoreBtn, ui->studentBtn, ui->statisticBtn};
    for (const auto &item: pointers) {
        connect(item, &QPushButton::clicked, this, &SideBar::changePage);
    }



    initWidget();
}

void SideBar::initWidget() {

    indexWidget = new IndexWidget(db, this);
    studentWidget = new StudentWidget(db, this);
    scoreWidget = new ScoreWidget(db, this);
    statisticWidget = new StatisticWidget(this);


    ui->conetent->removeWidget(ui->page_3);
    ui->conetent->removeWidget(ui->page_4);
    ui->conetent->addWidget(indexWidget);
    ui->conetent->addWidget(scoreWidget);
    ui->conetent->addWidget(studentWidget);
    ui->conetent->addWidget(statisticWidget);

    qDebug() << ui->conetent->count();

    ui->conetent->setCurrentIndex(0);
    ui->indexBtn->setChecked(true);



}
SideBar::~SideBar()
{
    delete ui;
}

void SideBar::changePage() {
    auto *sender = dynamic_cast<QPushButton *>(QObject::sender());
    sender->setChecked(false);
    if (ui->conetent->currentIndex() == 2 && sender != ui->studentBtn) {
        if (!dynamic_cast<StudentWidget*>(ui->conetent->currentWidget())->changePage()) {
            return;
        }
    }


    for (const auto &item: pointers) {
        item->setChecked(false);
    }
    sender->setChecked(true);


    int i = (int)pointers.indexOf(sender);
    ui->conetent->setCurrentIndex(i);

}


