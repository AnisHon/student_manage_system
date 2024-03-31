#include "scorewidget.h"
#include "ui_scorewidget.h"

ScoreWidget::ScoreWidget(const QSqlDatabase& database, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScoreWidget)
{
    ui->setupUi(this);
    db = database;
}

ScoreWidget::~ScoreWidget()
{
    delete ui;
}
