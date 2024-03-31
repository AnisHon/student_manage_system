#include <QComboBox>
#include "comboboxdelegate.h"


ComboBoxDelegate::ComboBoxDelegate(const QStringList &list, QObject *parent): QStyledItemDelegate(parent)
{



    dropdownText = list;
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(option);
    Q_UNUSED(index);
    auto *editor = new QComboBox(parent);
    editor->setFrame(false);
    editor->addItems(dropdownText);
    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    auto *comboBox = dynamic_cast<QComboBox*>(editor);
    comboBox->setCurrentText(index.data(Qt::EditRole).toString());
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const {
    auto *pComboBox = dynamic_cast<QComboBox*>(editor);
    QString value = pComboBox->currentText();
    model->setData(index, value, Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

