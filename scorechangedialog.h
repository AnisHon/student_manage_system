#ifndef SCORECHANGEDIALOG_H
#define SCORECHANGEDIALOG_H

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
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

private:
    Ui::ScoreChangeDialog *ui;
    QSqlRelationalTableModel *model;
};

#endif // SCORECHANGEDIALOG_H
