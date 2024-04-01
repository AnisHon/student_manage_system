#include "scorechangedialog.h"
#include "ui_scorechangedialog.h"
#include <QSqlRelation>
ScoreChangeDialog::ScoreChangeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScoreChangeDialog)
{
    ui->setupUi(this);

    model = new QSqlRelationalTableModel(this);
    model->setTable("score");
    model->setRelation(model->fieldIndex("subject_id"), QSqlRelation("subject", "id", "name"));
    model->setHeaderData(model->fieldIndex("score"), Qt::Horizontal, "分数");
    model->setHeaderData(model->fieldIndex("subject_id"), Qt::Horizontal, "科目");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    ui->tableView->setModel(model);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setColumnHidden(model->fieldIndex("id"), true);
    ui->tableView->setColumnHidden(model->fieldIndex("stu_id"), true);
}

void ScoreChangeDialog::setName(const QString &name) {

}

void ScoreChangeDialog::setStudentId(const QString &studentId) {

}

void ScoreChangeDialog::setId(int id) {

}

ScoreChangeDialog::~ScoreChangeDialog()
{
    delete ui;
}
