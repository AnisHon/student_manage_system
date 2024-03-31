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

private slots:
    void on_ComboBox_activated(int index);

private:
    void initPieChart();
    void initLineChart();
    void initBarChart(int i);
    void reloadCharts();

    static int totalCount();
    static int totalCountPreSubject(int id);
    static int totalCountWithin(int a, int b);
    static int totalCountPreSubjectWithin(int a, int b, int id);
    static QMap<double, int> averageScores();
    static int subjectSum(int id);
    static double subjectAverage(int id);
    static QMap<QString, int> getSubjectNames();
    static QString getSubjectName(int id);
    static QStringList getProjectScores(int id);

void showEvent(QShowEvent *event) override;

private:
    Ui::StatisticWidget *ui;
    QMap<int, int> subjectToIndex;


};

#endif // STATISTICWIDGET_H
