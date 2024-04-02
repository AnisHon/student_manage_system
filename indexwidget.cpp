#include "indexwidget.h"
#include "ui_indexwidget.h"
#include <QDateTime>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>

IndexWidget::IndexWidget(const QSqlDatabase& database, QWidget *parent)
    : QWidget(parent),
    ui(new Ui::IndexWidget),
    db{database}
{
    ui->setupUi(this);

    ui->portrait->setPixmap(QPixmap(":/icon/portraits/default_portrait.png").scaledToHeight(ui->portrait->height()));
    ui->name->setText("<h2>您好 🤪👉👈🤣</h2>");

    initModel();


    auto *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    connect(timer, &QTimer::timeout, this, &IndexWidget::setTimeLabel);
    setTimeLabel();


    setDatabaseLabel();

    ui->cpu->setMax(100);
    ui->mem->setMax(100);
    ui->cpu->setCurrentIndex(75);
    ui->mem->setCurrentIndex(75);



}

IndexWidget::~IndexWidget()
{
    delete ui;
}

void IndexWidget::initModel() {
    model = new QSqlTableModel(this);
    model->setTable("subject");

//    ui->tableWidget

    ui->tableView->setModel(model);
    model->select();

    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->setColumnWidth(1, ui->tableView->geometry().width() * 2 - 16);
    qDebug() << ui->tableView->geometry().width();

}

void IndexWidget::setTimeLabel() {
    auto font = ui->time->font();
    font.setFamily("Microsoft YaHei");
    ui->time->setText(QString("当前时间：%1").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")));
    ui->time->setFont(font);
}

void IndexWidget::setDatabaseLabel() {
    ui->database->setText(QString("数据库：%1").arg(db.driverName()));
    ui->table->setText(QString("库名称：%1").arg(db.databaseName()));

    QSqlQuery query("select sum(data_length/1024/1024) as data from information_schema.tables");
    query.exec();
    query.next();
    int used = query.value(0).toInt();
    ui->storeLabel->setText(QString("存储能力：%0M/%1M").arg(used).arg(2 * 1024));
    ui->storeBar->setMaximum(2 * 1024);
    ui->storeBar->setValue(used <= 10 ? used * 10 : used);
}
