#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QFile>
#include <QSqlError>
LoginWindow::LoginWindow(QWidget *main, QWidget *parent)
    : QWidget(parent),
    mainWindow(main),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    auto *lock = new QAction(this);
    lock->setIcon(QIcon(":/icon/icon/lock.png"));
    auto *user = new QAction(this);
    user->setIcon(QIcon(":/icon/icon/user.png"));

    ui->username->addAction(user, QLineEdit::LeadingPosition);
    ui->password->addAction(lock, QLineEdit::LeadingPosition);

    this->setWindowFlags(Qt::Window |Qt::FramelessWindowHint);
    this->setWindowModality(Qt::WindowModality::ApplicationModal);
    this->setFixedSize(470, 400);

    auto window = dynamic_cast<MainWindow *>(main);
    connect(window, &MainWindow::logout, this, &LoginWindow::logout);
    connect(this, &LoginWindow::setWelcomeTitle, window, &MainWindow::setWelcomeTitle);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}



void LoginWindow::on_username_textChanged(const QString &arg1) {
    QSqlQuery query;
    query.prepare("select portrait from account where teacher_id = :id");
    query.bindValue(":id", arg1);
    query.exec();
    query.next();
    if (query.isNull(0)) {
        ui->portrait->setPixmap(QPixmap(":/icon/portraits/default_portrait.png"));
        return;
    }
    auto path = "/Users/anishan/Project/qt/student_manage_system/portraits/" + query.value(0).toString();
    QFile file(path);
    if (!file.exists()) {
        return;
    }

    QPixmap pixmap(path);
    ui->portrait->setPixmap(pixmap);
}

void LoginWindow::on_loginBtn_clicked()
{
    QSqlQuery query;
    query.prepare("select name, portrait from account where teacher_id = :id and password = :pass");
    query.bindValue(":id", ui->username->text());
    query.bindValue(":pass", ui->password->text());
    query.exec();
    query.next();

    if (query.isNull(0)) {
        ui->error->setText("用户名或密码错误");
    } else {
        emit setWelcomeTitle(query.value(0).toString(), query.value(1).toString());
        mainWindow->show();
        this->close();
    }


}

void LoginWindow::logout() {
    mainWindow->close();
    this->show();
}

