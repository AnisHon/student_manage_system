#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QChartView>

namespace Ui {
class ScoreWidget;
}

class ScoreWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreWidget(const QSqlDatabase& database, QWidget *parent = nullptr);
    ~ScoreWidget() override;

private:
    Ui::ScoreWidget *ui;
    QSqlDatabase db;
};

#endif // SCOREWIDGET_H
