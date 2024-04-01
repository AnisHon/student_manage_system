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
    this->setCentralWidget(sideBar);

//    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->installEventFilter(this);

//    this->setWindowFlags(Qt::FramelessWindowHint);//设置无窗口框架边界
//    this->setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
//    this->setAttribute(Qt::WA_TranslucentBackground);

}

MainWindow::~MainWindow()
{
    delete ui;
}


