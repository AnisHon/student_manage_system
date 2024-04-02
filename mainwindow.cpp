#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
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

//    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->installEventFilter(this);

//    this->setWindowFlags(Qt::FramelessWindowHint);//设置无窗口框架边界
//    this->setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
//    this->setAttribute(Qt::WA_TranslucentBackground);


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


