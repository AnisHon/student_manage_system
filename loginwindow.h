#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *main, QWidget *parent = nullptr);
    ~LoginWindow() override;

signals:
    void setWelcomeTitle(const QString& name, const QString& path);

private slots:
    void on_username_textChanged(const QString &arg1);

    void on_loginBtn_clicked();

    void logout();


private:
    Ui::LoginWindow *ui;
    QWidget *mainWindow;
};

#endif // LOGINWINDOW_H
