#include "aligncenterdelegate.h"



AlignCenterDelegate::AlignCenterDelegate(QObject *parent) : QStyledItemDelegate(parent) {

}

void AlignCenterDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {

    QStyleOptionViewItem new_option(option);
    new_option.displayAlignment = Qt::AlignCenter;

    QStyledItemDelegate::paint(painter, option, index);
}


