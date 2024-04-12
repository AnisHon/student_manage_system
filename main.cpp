#include "mainwindow.h"
#include "sidebar.h"
#include "loginwindow.h"
#include "properties.h"
#include "databaseconnectiondialog.h"
#include <QApplication>
#include <QStyleFactory>

QString basePath = "/Users/anishan/Project/qt/student_manage_system/portraits";


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
    db.open();
    return db;
}


QSqlDatabase initDatabase() {
    DatabaseConnectionDialog dialog;
    dialog.setModal(true);
    QSqlDatabase db;
    while(!db.isValid()) {
        db = connect(db);
        if (!db.isValid() && dialog.exec() == QDialog::Rejected) {
            exit(0);
        }

    }
    return db;
}

QString getStyleSheet() {
    QFile file(":/style/qss/main-style.qss");
    file.open(QIODevice::ReadOnly);
    auto array = file.readAll();
    file.close();
    return QString::fromUtf8(array);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    basePath = QCoreApplication::applicationFilePath();
//    qDebug() << basePath;
    app.setStyleSheet(getStyleSheet());
    QSqlDatabase db = initDatabase();

    MainWindow w;
//    w.show();
    LoginWindow login(&w);
    login.show();


    return QApplication::exec();
}

