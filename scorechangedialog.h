#ifndef SCORECHANGEDIALOG_H
#define SCORECHANGEDIALOG_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QMenu>
namespace Ui {
class ScoreChangeDialog;
}

class ScoreChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScoreChangeDialog(QWidget *parent = nullptr);
    ~ScoreChangeDialog();

    void setName(const QString &name);
    void setStudentId(const QString &studentId);
    void setId(int id);

private slots:
    void on_okBtn_clicked();

    void on_restoreBtn_clicked();

    void on_cancelBtn_clicked();

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void on_addAction_triggered();

    void on_deleteAction_triggered();

    void on_restoreAction_triggered();

private:
    Ui::ScoreChangeDialog *ui;
    QSqlRelationalTableModel *model;
    QMenu *menu;
    int id_;
    QItemSelectionModel *selectionModel;
};

#endif // SCORECHANGEDIALOG_H
