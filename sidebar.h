#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "statisticwidget.h"
#include "scorewidget.h"
#include "indexwidget.h"
#include "studentwidget.h"

#include <QWidget>
#include <QPushButton>


namespace Ui {
class SideBar;
}

class SideBar : public QWidget
{
    Q_OBJECT

public:
    explicit SideBar(QWidget *parent = nullptr);
    ~SideBar() override;

private slots:
    void changePage();

private:
    void initWidget();




private:
    Ui::SideBar *ui;
    QVector<QPushButton *> pointers;

    IndexWidget *indexWidget;
    StudentWidget *studentWidget;
    ScoreWidget *scoreWidget;
    StatisticWidget *statisticWidget;
    QSqlDatabase db;

};

#endif // SIDEBAR_H
