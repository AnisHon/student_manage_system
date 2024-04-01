#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include "scorechangedialog.h"

#include <QWidget>
#include <QSqlDatabase>
#include <QChartView>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QItemSelectionModel>

namespace Ui {
class ScoreWidget;
}

class ScoreWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreWidget(const QSqlDatabase& database, QWidget *parent = nullptr);
    ~ScoreWidget() override;


private slots:
    void on_sortMethod_activated(int index);

    void on_sortColumn_activated(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_addBtn_clicked();

    void on_changeBtn_clicked();

    void on_deleteBtn_clicked();

    void on_refreshBtn_clicked();

private:
    QSqlQuery queryForScore();
    static QMap<int, QString> queryForSubjects();
    void initModel();
    void loadSubjects();
    void updateModel();
private:
    Ui::ScoreWidget *ui;
    QSqlDatabase db;
    QMap<int, QString> subjects;


    QSqlTableModel *model;
    QString filter = "";
    int sortColumn = -1;
    Qt::SortOrder order = Qt::AscendingOrder;
    QSqlRecord record;
    QItemSelectionModel *selectionModel;

    ScoreChangeDialog *scoreChangeDialog;

};

#endif // SCOREWIDGET_H
