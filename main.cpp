#include "mainwindow.h"
#include "sidebar.h"
#include "loginwindow.h"
#include "properties.h"
#include "databaseconnectiondialog.h"
#include <QApplication>
#include <QStyleFactory>


QSqlDatabase connect(QSqlDatabase db) {
    Properties properties("config.properties");
    if (!properties.exist()) {
        DatabaseConnectionDialog dialog;
        dialog.setModal(true);
        if (dialog.exec() == QDialog::Rejected) {
            exit(0);
        }
    }
    properties.load();

    db = QSqlDatabase::addDatabase(properties.get("driver"));
    db.setHostName(properties.get("url"));
    db.setDatabaseName(properties.get("table"));
    db.setUserName(properties.get("username"));
    db.setPassword(properties.get("password"));
//    qDebug() << properties.get("driver");
//    qDebug() << properties.get("url");
//    qDebug() << properties.get("table");
//    qDebug() << properties.get("username");
//    qDebug() << properties.get("password");
    return db;
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFile file(":/style/qss/main-style.qss");
    file.open(QIODevice::ReadOnly);
    auto array = file.readAll();
    app.setStyleSheet(QString::fromUtf8(array));



    QSqlDatabase db;
    while(true) {
        db = connect(db);

        if (!db.open()) {
            DatabaseConnectionDialog dialog;
            dialog.setModal(true);
            if (dialog.exec() == QDialog::Rejected) {
                exit(0);
            }
        } else {
            break;
        }
    }

    MainWindow w(db);
    LoginWindow login(&w);
    login.show();


    return QApplication::exec();
}

