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
    explicit IndexWidget(QWidget *parent = nullptr);
    ~IndexWidget() override;


public slots:
    void initWelcomeTitle(const QString& name, const QString& path);

private slots:
    void on_addAction_triggered();

    void on_delAction_triggered();

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void setCircle();
private:
    void initModel();
    void setTimeLabel();
    void setDatabaseLabel();
    void initMenu();


private:
    Ui::IndexWidget *ui;
    QSqlTableModel *model;
    QMenu *menu;
    QString limit;

};

#endif // INDEXWIDGET_H
