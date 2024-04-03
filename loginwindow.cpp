#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    //todo
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}
