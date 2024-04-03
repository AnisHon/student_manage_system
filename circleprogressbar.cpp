#include "circleprogressbar.h"
#include "ui_circleprogressbar.h"
#include <QPainter>
#include <QBarCategoryAxis>
#include <QTimer>


CircleProgressBar::CircleProgressBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CircleProgressBar)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CircleProgressBar::animationBar);
}

CircleProgressBar::~CircleProgressBar()
{
    delete ui;
}

void CircleProgressBar::paintEvent(QPaintEvent *event) {

    paintBar();
}

void CircleProgressBar::setCurrentIndex(int index) {
    display_ = current_;
    current_ = index;
    timer->setInterval(10);
    timer->start();

}

void CircleProgressBar::setMax(int max) {
    max_ = max;
}

void CircleProgressBar::paintBar() {
    if (display_ >= current_) {
        timer->stop();
    } else {
        display_++;
    }
    QPainter painter(this);
    auto rect = this->rect();
    auto width = std::min(rect.width(), rect.height());
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::PenStyle::NoPen);
    painter.translate(rect.width() / 2, rect.height() / 2);
//    painter.scale(width * 0.9, width * 0.9);

    int w = -width / 2;

//    painter.setBrush(QColor("#0ebeff"));
//    painter.drawEllipse(w, w, width, width);

    int deg = 360 * 16 * display_ / max_;

    QConicalGradient gradient(0, 0, 90);
    gradient.setColorAt(0, "#0ebeff");
    gradient.setColorAt(0.75, "#7987dd");
    gradient.setColorAt(0.5, "#c95ec4");
    gradient.setColorAt(1.0, "#ff42b3");
    painter.setBrush(gradient);
    painter.drawPie(w, w, width, width, 90 * 16, -deg);

    painter.setBrush(Qt::white);
    painter.drawEllipse(w * 0.8, w * 0.8, width * 0.8, width * 0.8);

}

void CircleProgressBar::animationBar() {
    QWidget::update();
}
