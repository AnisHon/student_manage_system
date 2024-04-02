#ifndef INDEXWIDGET_H
#define INDEXWIDGET_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
    class IndexWidget;
}

class IndexWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IndexWidget(const QSqlDatabase& database, QWidget *parent = nullptr);
    ~IndexWidget() override;
private:
    void initModel();
    void setTimeLabel();
    void setDatabaseLabel();

private:
    Ui::IndexWidget *ui;
    QSqlTableModel *model;
    QSqlDatabase db;
};

#endif // INDEXWIDGET_H
