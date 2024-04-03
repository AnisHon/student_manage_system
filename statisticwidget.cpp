#include "statisticwidget.h"
#include "ui_statisticwidget.h"

#include <QPieSeries>
#include <QSqlQuery>
#include <QValueAxis>
#include <QLineSeries>
#include <QMap>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QSqlRecord>


StatisticWidget::StatisticWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatisticWidget)
{
    ui->setupUi(this);
    ui->pie->setChart(new QChart);
    ui->line->setChart(new QChart);
    ui->bar->setChart(new QChart);
    reloadCharts();
}

StatisticWidget::~StatisticWidget()
{
    delete ui;
}

void StatisticWidget::initPieChart() {

    
    QChart *chart = ui->pie->chart();
    chart->removeAllSeries();

    auto *pieSeries = new QPieSeries;

    QVector<int> counts = {
            totalCountWithin(0, 60),
            totalCountWithin(60, 70),
            totalCountWithin(70, 80),
            totalCountWithin(80, 90),
            totalCountWithin(90, 100)
    };
    QStringList list = {
            "不及格",
            "及格",
            "中等",
            "良好",
            "优秀",
    };

    for (int i = 0; i < counts.size(); ++i) {
        pieSeries->append(list[i], counts[i]);
    }
    for (int i = 0; i < counts.size(); ++i) {
        auto *slice = pieSeries->slices()[i];
        if (slice->value() != 0) {
            slice->setLabel(QString("%1：%2人").arg(list[i]).arg(counts[i]));
            slice->setLabelVisible(true);
        } else {
            slice->setLabelVisible(false);
        }
    }
    chart->addSeries(pieSeries);
    chart->setTitle("分数比例");
    chart->legend()->setAlignment(Qt::AlignLeft);
    chart->setAnimationOptions(QChart::SeriesAnimations);


}

void StatisticWidget::initLineChart() {


    
    QChart *pChart = ui->line->chart();
    auto *chart = new QChart();
    ui->line->setChart(chart);
    delete pChart;



    auto axisX = new QValueAxis();
    auto axisY = new QValueAxis();


    axisX->setRange(0, 100);
    axisX->setTitleText("分数");
    axisY->setRange(0, totalCount());
    axisY->setLabelFormat("%d");
    axisY->setTitleText("人数");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    auto *lineSeries = new QLineSeries();
    lineSeries->setName("分段人数");
    chart->addSeries(lineSeries);
    lineSeries->attachAxis(axisX);
    lineSeries->attachAxis(axisY);

    QMap<double, int> map = averageScores();
    for (const auto &item: map.asKeyValueRange()) {
//        qDebug() << item;
        lineSeries->append(item.first, item.second);
    }
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("分段人数");

}

void StatisticWidget::initBarChart(int i) {
    
    QChart *pChart = ui->bar->chart();
    auto *chart = new QChart;
    ui->bar->setChart(chart);
    delete pChart;
    chart->removeAllSeries();


    QVector<int> counts = {
            totalCountPreSubjectWithin(0, 19, i),
            totalCountPreSubjectWithin(20, 39, i),
            totalCountPreSubjectWithin(40, 59, i),
//            totalCountPreSubjectWithin(50, 60, 1),
            totalCountPreSubjectWithin(60, 79, i),
//            totalCountPreSubjectWithin(70, 80, 1),
            totalCountPreSubjectWithin(80, 89, i),
            totalCountPreSubjectWithin(90, 100, i)
    };
    
    QStringList list = {
            "0-19",
            "20-39",
            "40-59",
            "60-79",
            "80-89",
            "90-100",
    };

    auto *barSeries = new QBarSeries;
    auto *barSet = new QBarSet("人数");
    barSeries->append(barSet);
    barSeries->setName("分段人数");

    for (const auto &item: counts){
        barSet->append(item);
    }

    auto *axisY = new QValueAxis;
    axisY->setRange(0, totalCountPreSubject(i));
    axisY->setTitleText("人数");
    axisY->setLabelFormat("%d");
    auto *categoryAxis = new QBarCategoryAxis;
    categoryAxis->setTitleText("分段");
    categoryAxis->append(list);

    chart->addSeries(barSeries);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(categoryAxis, Qt::AlignBottom);

    barSeries->attachAxis(axisY);
    barSeries->attachAxis(categoryAxis);
    barSeries->setLabelsVisible(true);
//    barSeries->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);


    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle(getSubjectName(i) + "的人数分布");
//    chart->legend()->setAlignment(Qt::AlignBottom);

    
}

void StatisticWidget::reloadCharts() {

    auto subjects = getSubjectNames();
    ui->ComboBox->clear();
    for (const auto &item: subjects.asKeyValueRange()) {
        ui->ComboBox->addItem(item.first, item.second);
    }
    int id = ui->ComboBox->currentData().toInt();
    initPieChart();
    initLineChart();
    initBarChart(id);

    ui->average->setText(QString("<h2>平均分：%1</h2>").arg(subjectSum(id)));
    ui->total->setText(QString("<h3>总人数：%1</h3>").arg(subjectAverage(id)));
    ui->listWidget->clear();
    ui->listWidget->addItems(getProjectScores(id));
}



int StatisticWidget::totalCount() {
    QSqlQuery sqlQuery;
    sqlQuery.setForwardOnly(true);
    sqlQuery.exec("select count(*) from (select distinct stu_id from score) as ssi");
    sqlQuery.next();
    return sqlQuery.value(0).toInt();
}

int StatisticWidget::totalCountPreSubject(int id) {
    QSqlQuery sqlQuery;
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select count(*) from score where subject_id = :0");
    sqlQuery.bindValue(0, id);
    sqlQuery.exec();
    sqlQuery.next();
    return sqlQuery.value(0).toInt();
}

int StatisticWidget::totalCountWithin(int a, int b) {
    QSqlQuery sqlQuery;
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select count(*) from (select avg(score) as average from score group by stu_id) as sa where sa.average >= :0 and sa.average <= :1");
    sqlQuery.bindValue(0, a);
    sqlQuery.bindValue(1, b);
    sqlQuery.exec();
    sqlQuery.next();
    return sqlQuery.value(0).toInt();
}

QMap<double, int> StatisticWidget::averageScores() {
    QMap<double, int> averages;



    QSqlQuery sqlQuery;
    sqlQuery.setForwardOnly(true);
    sqlQuery.exec("select  average, count(*) from (select avg(score) as average from score group by stu_id) as sa group by sa.average");
    while(sqlQuery.next()) {
        averages.insert(sqlQuery.value(0).toDouble(), sqlQuery.value(1).toInt());
    }
    return averages;
}

int StatisticWidget::totalCountPreSubjectWithin(int a, int b, int id) {


    QSqlQuery sqlQuery;
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare("select count(*) from (select score as average from score where subject_id = :0) as sa where sa.average >= :1 and sa.average <= :2");
    sqlQuery.bindValue(0, id);
    sqlQuery.bindValue(1, a);
    sqlQuery.bindValue(2, b);
    sqlQuery.exec();
    sqlQuery.next();
    return sqlQuery.value(0).toInt();
}

void StatisticWidget::showEvent(QShowEvent *event) {
    reloadCharts();
    QWidget::showEvent(event);
}

QString StatisticWidget::getSubjectName(int id) {
    QSqlQuery query;
    query.prepare("select name from subject where id = :0");
    query.bindValue(0, id);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QMap<QString, int> StatisticWidget::getSubjectNames() {
    QMap<QString, int> map;
    QSqlQuery query;
    query.setForwardOnly(true);
    query.exec("select id, name from subject");
    while (query.next()) {
        map.insert(query.value(1).toString(), query.value(0).toInt());
    }
    return map;
}

int StatisticWidget::subjectSum(int id) {
    QSqlQuery query;
    query.prepare("select sum(score) from score where subject_id = :0");
    query.bindValue(0, id);
    query.exec();
    query.next();

    return query.value(0).toInt();
}

double StatisticWidget::subjectAverage(int id) {
    QSqlQuery query;
    query.prepare("select avg(score) from score where subject_id = :0");
    query.bindValue(0, id);
    query.exec();
    query.next();

    return query.value(0).toDouble();
}


QStringList StatisticWidget::getProjectScores(int id) {
    QStringList list;

    QSqlQuery query;
    query.prepare("select concat(name, ':',score) from score left join db_qt01.student s on s.id = score.stu_id where subject_id = :1");
    query.bindValue(0, id);
    query.exec();
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}


void StatisticWidget::on_ComboBox_activated(int index)
{
    Q_UNUSED(index);
//    int id = heightForWidth(subjects.value(ui->ComboBox->currentText()));
//    qDebug() << ui->ComboBox->currentText();
//    qDebug() << subjects;
    int id = ui->ComboBox->currentData().toInt();
    initBarChart(id);
    ui->average->setText(QString("<h2>平均分：%1</h2>").arg(subjectSum(id)));
    ui->total->setText(QString("<h3>总人数：%1</h3>").arg(subjectAverage(id)));

    ui->listWidget->clear();
    ui->listWidget->addItems(getProjectScores(id));

}

