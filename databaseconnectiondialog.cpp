#include "databaseconnectiondialog.h"
#include "ui_databaseconnectiondialog.h"
#include <QFile>
#include <QTextStream>
#include <QFileInfo>

DatabaseConnectionDialog::DatabaseConnectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DatabaseConnectionDialog)
{
    ui->setupUi(this);
}

DatabaseConnectionDialog::~DatabaseConnectionDialog()
{
    delete ui;
}

void DatabaseConnectionDialog::on_commit_clicked()
{
    QFile file("config.properties");
    file.open(QIODeviceBase::WriteOnly | QIODeviceBase::Truncate | QIODevice::Text);
    QTextStream textStream(&file);
    textStream << "driver=" << ui->driver->text() << "\n";
    textStream << "url=" << ui->url->text() << "\n";
    textStream << "table=" << ui->tableName->text() << "\n";
    textStream << "username=" << ui->username->text() << "\n";
    textStream << "password=" << ui->password->text() << "\n";
    file.close();
//    qDebug() << QFileInfo("cf.properties").absoluteFilePath();
    accept();
}

void DatabaseConnectionDialog::closeEvent(QCloseEvent *) {
   reject();
}

