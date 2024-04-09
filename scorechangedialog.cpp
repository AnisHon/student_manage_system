#include "scorechangedialog.h"
#include "ui_scorechangedialog.h"
#include "spinboxdelegate.h"
#include <QSqlRelation>
#include <QMessageBox>
#include <QSqlError>
#include <QRect>
#include <QSqlRecord>

ScoreChangeDialog::ScoreChangeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScoreChangeDialog)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(this);
    model->setTable("score");

    model->setHeaderData(model->fieldIndex("score"), Qt::Horizontal, "分数");
    model->setHeaderData(model->fieldIndex("subject_id"), Qt::Horizontal, "科目");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->tableView->setModel(model);

    selectionModel = new QItemSelectionModel(model, this);
    ui->tableView->setSelectionModel(selectionModel);

    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("stu_id"), true);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("score"), new SpinBoxDelegate(this));

    model->setRelation(model->fieldIndex("subject_id"), QSqlRelation("subject", "id", "name"));

    this->setWindowFlag(Qt::WindowStaysOnTopHint, true);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    menu = new QMenu;

    menu->addAction(ui->addAction);
    menu->addAction(ui->deleteAction);
    menu->addSeparator();
    menu->addAction(ui->restoreAction);
}

void ScoreChangeDialog::setName(const QString &name) {
    ui->name->setText(name);

}

void ScoreChangeDialog::setStudentId(const QString &studentId) {
    ui->studentId->setText(studentId);
}

void ScoreChangeDialog::setId(int id) {
    model->setFilter(QString("stu_id = %1").arg(id));
    model->select();
    this->id_ = id;

}

ScoreChangeDialog::~ScoreChangeDialog()
{
    delete ui;
}

void ScoreChangeDialog::on_okBtn_clicked()
{

    for (int i = 0; i < model->rowCount() - 1; ++i) {
        QString temp1 = model->data(model->index(i, 2)).toString();
        for (int j = i + 1; j < model->rowCount(); ++j) {
            QString temp2 = model->data(model->index(j, 2)).toString();
            if (temp1 == temp2) {
                QMessageBox::critical(this, "错误", QString("科目重复：%0 %1 -> %2").arg(temp1).arg(i + 1).arg(j + 1));
                return;
            }
        }

    }

    if (!model->submitAll()) {
        QMessageBox::critical(this, "错误", QString("发生以下错误，请检查是否正确\n%1").arg(model->lastError().text()));
    } else {
        close();
    }
}


void ScoreChangeDialog::on_restoreBtn_clicked()
{
    model->revertAll();
}


void ScoreChangeDialog::on_cancelBtn_clicked()
{
    close();
}


void ScoreChangeDialog::on_tableView_customContextMenuRequested(const QPoint &pos)
{

    if (!ui->tableView->currentIndex().isValid()) {
        return;
    }

    menu->exec(QCursor::pos());
}


void ScoreChangeDialog::on_addAction_triggered()
{
    auto record = model->record();
    record.setValue(model->fieldIndex("stu_id"), id_);
    model->insertRecord(model->rowCount(), record);
}


void ScoreChangeDialog::on_deleteAction_triggered()
{
//    model->select();
//    model->setData(model->index(ui->tableView->currentIndex().row(), 3), 12);
//    qDebug() << model->data(model->index(ui->tableView->currentIndex().row(), 3));
    model->removeRow(selectionModel->currentIndex().row());


}


void ScoreChangeDialog::on_restoreAction_triggered()
{
    on_restoreBtn_clicked();
}

