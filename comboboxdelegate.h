#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class ComboBoxDelegate: public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit ComboBoxDelegate(const QStringList &list, QObject *parent = nullptr);

    QWidget * createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;


public:
    QStringList dropdownText;
};

#endif // COMBOBOXDELEGATE_H
