#include "mainwindow.h"
#include "sidebar.h"
#include "loginwindow.h"
#include <QApplication>
#include <QStyle>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFile file(":/style/qss/main-style.qss");
    file.open(QIODevice::ReadOnly);
    auto array = file.readAll();
    app.setStyleSheet(QString::fromUtf8(array));






    MainWindow w;
    LoginWindow login(&w);
    login.show();


    return QApplication::exec();
}
