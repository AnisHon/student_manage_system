#include "indexwidget.h"
#include "ui_indexwidget.h"
#include <QDateTime>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QMenu>
#include <QSqlRecord>
#include <QRandomGenerator>

IndexWidget::IndexWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::IndexWidget)
{
    ui->setupUi(this);

    ui->portrait->setPixmap(QPixmap(":/icon/portraits/default_portrait.png").scaledToHeight(ui->portrait->height()));
    ui->name->setText("<h2></h2>");

    initModel();


    auto *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();

    auto *timer2 = new QTimer(this);
    timer2->setInterval(5000);
    timer2->start();
    connect(timer, &QTimer::timeout, this, &IndexWidget::setTimeLabel);
    connect(timer2, &QTimer::timeout, this, &IndexWidget::setCircle);
    setTimeLabel();


    setDatabaseLabel();

    ui->cpu->setMax(100);
    ui->mem->setMax(100);
    ui->cpu->setCurrentIndex(0);
    ui->mem->setCurrentIndex(0);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    initMenu();

    ui->cpu->setText("<h3>数据库瞬时压力</h3><p>0%</p>");
    ui->mem->setText("<h3>访问压力</h3><p>0%</p>");

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

}

void IndexWidget::setTimeLabel() {
    auto font = ui->time->font();
    font.setFamily("Microsoft YaHei");
    ui->time->setText(QString("当前时间：%1").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss")));
    ui->time->setFont(font);
}

void IndexWidget::setDatabaseLabel() {
    QSqlDatabase db = QSqlDatabase::database();
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

void IndexWidget::initWelcomeTitle(const QString& name, const QString& path) {
    ui->name->setText(QString("<h3>您好 %1</h3>").arg(name));
    QString filePath = "/Users/anishan/Project/qt/student_manage_system/portraits/" + path;
    QFile file(filePath);
    if (file.exists()) {
        ui->portrait->setPixmap(QPixmap(filePath).scaledToHeight(ui->portrait->height()));
    }

}

void IndexWidget::initMenu() {
    menu = new QMenu(this);
    menu->addAction(ui->addAction);
    menu->addAction(ui->delAction);
//    menu->addAction("123");
}

void IndexWidget::on_addAction_triggered()
{
    auto temp = model->record();
    temp.setNull(0);
    temp.setValue(model->fieldIndex("name"), "未命名学科");
    int row = model->rowCount();
    model->insertRecord(row, temp);


    model->select();
    const QModelIndex &modelIndex = model->index(row, model->fieldIndex("name"));
    ui->tableView->setCurrentIndex(modelIndex);

}


void IndexWidget::on_delAction_triggered()
{
//    qDebug() << 12;
    if (!ui->tableView->currentIndex().isValid()) {
//        qDebug() << 21;
        return;

    }
    model->removeRow(ui->tableView->currentIndex().row());
    model->select();
}




void IndexWidget::on_tableView_customContextMenuRequested(const QPoint &pos)
{
    menu->exec(QCursor::pos());
}

void IndexWidget::setCircle() {
    QRandomGenerator rand(QDateTime::currentMSecsSinceEpoch());
    int i = rand.bounded(100);
    ui->cpu->setCurrentIndex(i);
    int i1 = rand.bounded(100);
    ui->mem->setCurrentIndex(i1);
    ui->cpu->setText(QString("<h3>数据库瞬时压力</h3><p>%1%</p>").arg(i));
    ui->mem->setText(QString("<h3>访问压力</h3><p>%1%</p>").arg(i1));
}

