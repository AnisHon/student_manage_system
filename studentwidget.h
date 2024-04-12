#ifndef STUDENTWIDGET_H
#define STUDENTWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QMenu>
#include "comboboxdelegate.h"
#include "LimitedQSqlTableModel.h"


extern QString basePath;

namespace Ui {
class StudentWidget;
}

class StudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWidget(QWidget *parent = nullptr);
    ~StudentWidget() override;

private slots:
    void on_genderBox_currentTextChanged(const QString &arg1);

    void on_searchEdit_editingFinished();

    void on_searchEdit_textChanged(const QString &arg1);

    void on_searchMethod_currentIndexChanged(int index);

    void on_addStudent_clicked();

    void on_deleteStudent_clicked();

    void on_submitBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

//    void on_pageSpan_valueChanged(int arg1);

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void on_pageNumber_valueChanged(int arg1);

private:
    void changeMappingRow(const QModelIndex &current, const QModelIndex &previous);

    void mappingRowChanged(int index);

    int queryAllCount();

    void initMenu();

    void initLimitPage();

    void filterChange();

private:
    void initTable();

public:
    bool changePage();

private:
    Ui::StudentWidget *ui;

    const QString base_dir = basePath;
    const QString base_path = base_dir + "/";
    const QString default_portrait = "default_portrait.png";

    QString searchFilter;
    QString pageFilter;

    LimitedQSqlTableModel *model;
    QItemSelectionModel *selectionModel;
    QDataWidgetMapper *mapper;
    ComboBoxDelegate *comboBoxDelegate;
    QMenu *menu;

    const int PAGE_COUNT = 15;
//    QString limit;

    enum SearchMethod {
        NAME = 0, ID
    };

};

#endif // STUDENTWIDGET_H
