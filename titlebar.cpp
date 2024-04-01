#include "titlebar.h"
#include "ui_titlebar.h"
#include <QKeyEvent>
#include <QMoveEvent>
TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TitleBar)
{
    ui->setupUi(this);
}

TitleBar::~TitleBar()
{
    delete ui;
}

void TitleBar::on_closeBtn_clicked()
{
    emit requestClose();
}



void TitleBar::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        beginPos = event->pos();
        isMovable = true;
    }
    QWidget::mousePressEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isMovable = false;

    }
    QWidget::mouseReleaseEvent(event);
}

void TitleBar::mouseMoveEvent(QMouseEvent *event) {
    if (isMovable) {
        auto global = QCursor::pos();
//        auto relative = event->pos();
//        qDebug() << global;
//        qDebug() << relative;

        emit moveWindow(global.x() - beginPos.x(), global.y() - beginPos.y());

    }
    QWidget::mouseMoveEvent(event);
}

