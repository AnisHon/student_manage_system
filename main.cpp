#include "mainwindow.h"
#include "sidebar.h"
#include <QApplication>
#include <QStyle>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // 设置应用程序的颜色方案
    MainWindow w;


    w.show();
    app.setStyleSheet("QGroupBox { background-color: transparent; border: none; } QLineEdit {border: 1px solid black;}");
    return QApplication::exec();
}
