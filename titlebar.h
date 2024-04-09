#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = nullptr);
    ~TitleBar();



    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

signals:
    void requestClose();

    void moveWindow(int x, int y);

private slots:
    void on_closeBtn_clicked();


    void on_pushButton_clicked();

private:
    Ui::TitleBar *ui;
    bool isMovable = false;
    QPoint beginPos;
    QWidget *parent;
};

#endif // TITLEBAR_H
