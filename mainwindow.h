#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sidebar.h"
#include "titlebar.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:
    void moveWindowTo(int x, int y);

signals:
    void logout();

    void setWelcomeTitle(const QString& name, const QString& path);

public:
    void requestLogout();

private:
    Ui::MainWindow *ui;
    SideBar *sideBar;
    TitleBar *titleBar;

};
#endif // MAINWINDOW_H
