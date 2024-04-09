#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "loginwindow.h"
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    sideBar = new SideBar(this);
    titleBar = new TitleBar(this);

    ui->verticalLayout->addWidget(titleBar);
    ui->verticalLayout->addWidget(sideBar);
//    this->setCentralWidget(sideBar);

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->installEventFilter(this);


    connect(titleBar, &TitleBar::requestClose, this, &MainWindow::close);
    connect(titleBar, &TitleBar::moveWindow, this, &MainWindow::moveWindowTo);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveWindowTo(int x, int y) {
//    qDebug() << x << " " << y;
    this->move(x, y);
}

void MainWindow::requestLogout() {
    emit logout();
}






