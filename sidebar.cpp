#include "sidebar.h"
#include "ui_sidebar.h"
#include "mainwindow.h"
#include <QPalette>
#include <QMouseEvent>
SideBar::SideBar(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::SideBar)

{

    ui->setupUi(this);
    pointers = {ui->indexBtn, ui->scoreBtn, ui->studentBtn, ui->statisticBtn};
    for (const auto &item: pointers) {
        item->installEventFilter(this);
    }




    initWidget();
}

void SideBar::initWidget() {

    indexWidget = new IndexWidget(this);
    studentWidget = new StudentWidget(this);
    scoreWidget = new ScoreWidget(this);
    statisticWidget = new StatisticWidget(this);


    ui->conetent->removeWidget(ui->page_3);
    ui->conetent->removeWidget(ui->page_4);
    ui->conetent->addWidget(indexWidget);
    ui->conetent->addWidget(scoreWidget);
    ui->conetent->addWidget(studentWidget);
    ui->conetent->addWidget(statisticWidget);

//    qDebug() << ui->conetent->count();

    ui->conetent->setCurrentIndex(0);
    ui->indexBtn->setChecked(true);


    auto mainWindow = dynamic_cast<MainWindow *>(parent());
    connect(mainWindow, &MainWindow::setWelcomeTitle, indexWidget, &IndexWidget::initWelcomeTitle);


}
SideBar::~SideBar()
{
    delete ui;
}

void SideBar::changePage(QPushButton *sender) {
//    sender->setChecked(false);
    if (sender->isChecked()) {
        return;
    }
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

bool SideBar::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick) {
        auto btn = dynamic_cast<QMouseEvent *>(event)->button();
        if (btn != Qt::LeftButton) {
            return false;
        }
        for (const auto &item: pointers) {
            if (watched == item) {
//                qDebug() << 1;
                changePage(dynamic_cast<QPushButton *>(watched));
                return true;
            }
        }
    }
    return QObject::eventFilter(watched, event);
}


