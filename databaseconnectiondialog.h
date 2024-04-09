#ifndef DATABASECONNECTIONDIALOG_H
#define DATABASECONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class DatabaseConnectionDialog;
}

class DatabaseConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseConnectionDialog(QWidget *parent = nullptr);
    ~DatabaseConnectionDialog();

    void closeEvent(QCloseEvent *) override;

private slots:
    void on_commit_clicked();



private:
    Ui::DatabaseConnectionDialog *ui;
};

#endif // DATABASECONNECTIONDIALOG_H
