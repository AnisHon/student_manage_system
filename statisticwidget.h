#ifndef STATISTICWIDGET_H
#define STATISTICWIDGET_H

#include <QWidget>

namespace Ui {
class StatisticWidget;
}

class StatisticWidget : public QWidget
{
    Q_OBJECT


public:
    explicit StatisticWidget(QWidget *parent = nullptr);
    ~StatisticWidget() override;

private:
    void initPieChart();
    void initLineChart();
    void initBarChart();
    void reloadCharts();

    static int totalCount();
    static int totalCountPreSubject(int id);
    static int totalCountWithin(int a, int b);
    static int totalCountPreSubjectWithin(int a, int b, int id);
    static QMap<double, int> averageScores();

void showEvent(QShowEvent *event) override;

private:
    Ui::StatisticWidget *ui;
};

#endif // STATISTICWIDGET_H
