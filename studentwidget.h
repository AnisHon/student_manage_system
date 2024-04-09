#ifndef STUDENTWIDGET_H
#define STUDENTWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QSqlTableModel>
#include <QDataWidgetMapper>

#include "comboboxdelegate.h"
namespace Ui {
class StudentWidget;
}

class StudentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWidget(const QSqlDatabase& database, QWidget *parent = nullptr);
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

private:
    void changeMappingRow(const QModelIndex &current, const QModelIndex &previous);

    void mappingRowChanged(int index);

    int queryAllCount();

private:
    void initTable();

public:
    bool changePage();

private:
    Ui::StudentWidget *ui;

    const QString base_dir = "/Users/anishan/Project/qt/student_manage_system/portraits/";
    const QString base_path = base_dir + "/";
    const QString default_portrait = "default_portrait.png";

    QSqlTableModel *model;
    QItemSelectionModel *selectionModel;
    QDataWidgetMapper *mapper;
    QSqlDatabase db;
    ComboBoxDelegate *comboBoxDelegate;

//    QString limit;


};

#endif // STUDENTWIDGET_H
