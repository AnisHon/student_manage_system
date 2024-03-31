#ifndef INDEXWIDGET_H
#define INDEXWIDGET_H

#include <QWidget>

namespace Ui {
class IndexWidget;
}

class IndexWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IndexWidget(QWidget *parent = nullptr);
    ~IndexWidget();

private:
    Ui::IndexWidget *ui;
};

#endif // INDEXWIDGET_H
