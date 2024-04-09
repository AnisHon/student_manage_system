#ifndef CIRCLEPROGRESSBAR_H
#define CIRCLEPROGRESSBAR_H

#include <QWidget>

namespace Ui {
class CircleProgressBar;
}

class CircleProgressBar : public QWidget
{
    Q_OBJECT

public:
    explicit CircleProgressBar(QWidget *parent = nullptr);
    ~CircleProgressBar() override;

    void paintEvent(QPaintEvent *event) override;

    void setCurrentIndex(int index);

    void setMax(int max);

    void setText(const QString &text);

private slots:
    void animationBar();

private:
    void paintBar();


private:
    Ui::CircleProgressBar *ui;
    QTimer *timer;
    int max_ = 1;
    int current_ = 0;
    int display_ = 0;

};

#endif // CIRCLEPROGRESSBAR_H
