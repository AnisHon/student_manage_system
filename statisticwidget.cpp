#include "statisticwidget.h"
#include "ui_statisticwidget.h"

#include <QPieSeries>
#include <QPieSeries>
#include <QSqlQuery>
#include <QValueAxis>
#include <QLineSeries>
#include <QMap>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>


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

    
    auto *chart = ui->line->chart();

    chart->removeAllSeries();

    auto axisX = new QValueAxis(this);
    auto axisY = new QValueAxis(this);


    axisX->setRange(0, 100);
    axisX->setTitleText("分数");
    axisY->setRange(0, totalCount());
    axisY->setLabelFormat("%d");
    axisY->setTitleText("人数");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    auto *lineSeries = new QLineSeries(this);
    lineSeries->setName("分段人数");
    chart->addSeries(lineSeries);
    lineSeries->attachAxis(axisX);
    lineSeries->attachAxis(axisY);

    QMap<double, int> map = averageScores();
    for (const auto &item: map.keys()) {
        lineSeries->append(item, map[item]);
    }
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("分段人数");

}

void StatisticWidget::initBarChart() {
    QChart *chart = ui->bar->chart();
    chart->removeAllSeries();
    
    QVector<int> counts = {
            totalCountPreSubjectWithin(0, 10, 1),
            totalCountPreSubjectWithin(10, 20, 1),
            totalCountPreSubjectWithin(20, 30, 1),
            totalCountPreSubjectWithin(30, 40, 1),
            totalCountPreSubjectWithin(40, 50, 1),
            totalCountPreSubjectWithin(50, 60, 1),
            totalCountPreSubjectWithin(60, 70, 1),
            totalCountPreSubjectWithin(70, 80, 1),
            totalCountPreSubjectWithin(80, 90, 1),
            totalCountPreSubjectWithin(90, 100, 1)
    };
    
    QStringList list;
    for (int i = 0; i < 10; ++i) {
        list << QString("%1-%2").arg(i * 10).arg((i + 1) * 10);
    }

    auto *barSeries = new QBarSeries;
    QBarSet *barSet = new QBarSet("人数");
    barSeries->append(barSet);
    barSeries->setName("分段人数");

    for (const auto &item: counts){
        barSet->append(item);
    }

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, totalCount());
    axisY->setTitleText("人数");
    QBarCategoryAxis *categoryAxis = new QBarCategoryAxis;
    categoryAxis->setTitleText("分段");
    categoryAxis->append(list);




    

    for (const auto &item: counts) {
        
    }
    
}

void StatisticWidget::reloadCharts() {
    initPieChart();
    initLineChart();
    initBarChart();
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
    sqlQuery.exec("select  average, count(*) from (select avg(score) as average from score group by stu_id) as sa group by sa.average;");
    while(sqlQuery.next()) {
        averages.insert(sqlQuery.value(0).toDouble(), sqlQuery.value(1).toInt());
    }
    return averages;
}

int StatisticWidget::totalCountPreSubjectWithin(int a, int b, int id) {


    QSqlQuery sqlQuery;
    sqlQuery.setForwardOnly(true);
    sqlQuery.prepare(" select count(*) from (select score as average from score where subject_id = :2) as sa where sa.average >= :0 and sa.average <= :1;");
    sqlQuery.bindValue(0, a);
    sqlQuery.bindValue(1, b);
    sqlQuery.bindValue(2, id);
    sqlQuery.exec();
    sqlQuery.next();
    return sqlQuery.value(0).toInt();
}

void StatisticWidget::showEvent(QShowEvent *event) {
    initLineChart();
    initPieChart();
    QWidget::showEvent(event);
}





