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
//    app.setStyleSheet("StatisticWidget, IndexWidget, ScoreWidget, StatisticWidget, StudentWidget {background-color: #ECECEB}");

    return app.exec();
}
