#include "indexwidget.h"
#include "ui_indexwidget.h"

IndexWidget::IndexWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::IndexWidget)
{
    ui->setupUi(this);
}

IndexWidget::~IndexWidget()
{
    delete ui;
}
