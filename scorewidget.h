#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include "scorechangedialog.h"
#include "CSVTool.h"

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
    void requestMenu(const QPoint &pos);


private slots:
    void on_sortMethod_activated(int index);

    void on_sortColumn_activated(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_changeBtn_clicked();

    void on_refreshBtn_clicked();

    void changeRow(const QModelIndex &current, const QModelIndex &previous);

    void on_inputAction_triggered();

    void on_outputAction_triggered();

    void on_outputAllAction_triggered();

    void on_pageIndex_editingFinished();

private:
    QSqlQuery queryForScore();
    static QMap<int, QString> queryForSubjects();
    void initModel();
    void loadSubjects();
    void updateModel();
    void initMenu();
    static void headerValidate(const CSVTool& tool);
    static QMap<int, int> mappingHeader(const QStringList& headers);

    static int getStudentId(const QString& studentId);

    static bool validateScore(const QString& str);

    static void insertScore(int student_id, const QStringList &scores, const QMap<int, int> &map);

    static int queryAllCount();

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

    QMenu *menu;

    int currentIndex = 1;
    const int ROW_COUNT = 15;


};

#endif // SCOREWIDGET_H
