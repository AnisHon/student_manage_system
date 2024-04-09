#include "spinboxdelegate.h"
#include <QSpinBox>
SpinBoxDelegate::SpinBoxDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
    this->max_ = 100;
    this->min_ = 0;
}
void SpinBoxDelegate::setMax(int max) {
    this->max_ = max;
}
void SpinBoxDelegate::setMin(int min) {
    this->min_ = min;
}

QWidget * SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(option);
    Q_UNUSED(index);
    auto *editor = new QSpinBox(parent);
    editor->setFrame(false);
    editor->setMaximum(max_);
    editor->setMinimum(min_);
    return editor;
}
void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    auto *comboBox = dynamic_cast<QSpinBox*>(editor);
    comboBox->setValue(index.data(Qt::EditRole).toInt());

}
void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    auto *spinBox = dynamic_cast<QSpinBox*>(editor);
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}
void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}