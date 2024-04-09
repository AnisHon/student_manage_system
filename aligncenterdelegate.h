#ifndef ALIGNCENTERDELEGATE_H
#define ALIGNCENTERDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class AlignCenterDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit AlignCenterDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

};

#endif // ALIGNCENTERDELEGATE_H
