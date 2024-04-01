#include "scorewidget.h"
#include "ui_scorewidget.h"
#include <QSqlRecord>
#include <QSqlError>
ScoreWidget::ScoreWidget(const QSqlDatabase& database, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScoreWidget)
{
    ui->setupUi(this);
    db = database;

    model = new QSqlTableModel(this);
    selectionModel = new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(selectionModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    scoreChangeDialog = new ScoreChangeDialog(this);

    connect(selectionModel, &QItemSelectionModel::currentRowChanged, this, &ScoreWidget::changeRow);

    loadSubjects();
    initModel();

}

ScoreWidget::~ScoreWidget()
{
    delete ui;
}

QSqlQuery ScoreWidget::queryForScore() {
    QString mainSql = "select stu.id as stu_id, stu.student_id as id, stu.name as name, %1 sum(score.score) as total, avg(score.score) as average from score "
                      "left join student stu on score.stu_id = stu.id "
                      "left join subject on score.subject_id = subject.id ";

    QString conditionalAggregation = "MAX(case when score.subject_id = %1 then score.score end) as %2,";
    QString aggregation;

    for (const auto &item: subjects.asKeyValueRange()) {
        aggregation += QString(conditionalAggregation).arg(item.first).arg(item.second);

    }
    mainSql = mainSql.arg(aggregation);

    if (!filter.isEmpty()) {
        mainSql += "where " + filter;
    }
    mainSql += " group by stu_id";
    if (sortColumn != -1) {
        if (order == Qt::AscendingOrder) {
            mainSql += " order by " + record.fieldName(sortColumn);
        } else {
            mainSql += " order by " + record.fieldName(sortColumn) + " desc";
        }
//        qDebug() << record.fieldName(sortColumn);
//        qDebug() << sortColumn;
    } else {
        mainSql += " order by id";
    }




    QSqlQuery query(mainSql);
//    qDebug() << mainSql.arg(aggregation);
    return query;
}

void ScoreWidget::loadSubjects() {
    subjects = queryForSubjects();
}

QMap<int, QString> ScoreWidget::queryForSubjects() {
    QMap<int, QString> scores;
    QSqlQuery sqlQuery;
    sqlQuery.exec("select * from subject");
    while (sqlQuery.next()) {
        scores.insert(sqlQuery.value(0).toInt(), sqlQuery.value(1).toString());
    }
    return scores;
}

void ScoreWidget::initModel() {
//    model = new QSqlTableModel(this);
    model->setQuery(queryForScore());


    record = model->record();
    // id is student_id not primary key
    model->setHeaderData(record.indexOf("id"), Qt::Horizontal, "学号");
    model->setHeaderData(record.indexOf("name"), Qt::Horizontal, "姓名");
    model->setHeaderData(record.indexOf("total"), Qt::Horizontal, "总分");
    model->setHeaderData(record.indexOf("average"), Qt::Horizontal, "平均分");
    model->setSort(model->fieldIndex("average"), Qt::DescendingOrder);
    // primary key is stu_id;
    ui->tableView->setColumnHidden(model->fieldIndex("stu_id"), true);

//    sortColumn = model->fieldIndex("id");

    for (int i = 1; i < model->columnCount(); ++i) {
        ui->sortColumn->addItem(model->headerData(i, Qt::Horizontal).toString(), i);
    }



//    qDebug() << model->lastError();

}






void ScoreWidget::on_sortMethod_activated(int index)
{
    order = index == 0 ? Qt::AscendingOrder : Qt::DescendingOrder;
    updateModel();
}


void ScoreWidget::on_sortColumn_activated(int index)
{

    Q_UNUSED(index);
    qDebug() << ui->sortColumn->currentData().toInt();
    sortColumn = ui->sortColumn->currentData().toInt();
    updateModel();
}


void ScoreWidget::on_lineEdit_textChanged(const QString &arg1)
{
    int sort = ui->comboBox->currentIndex();
    if (sort == 0) {
        filter = QString(" stu.name like '%%1%'").arg(arg1);
    } else {
        filter = QString(" stu.student_id like '%%1%'").arg(arg1);
    }

    updateModel();
}

void ScoreWidget::updateModel() {
//    delete model;
    QString current = ui->sortColumn->currentText();
    loadSubjects();
    ui->sortColumn->clear();
    initModel();
    ui->sortColumn->setCurrentText(current);
//    qDebug() << model->lastError();
}


void ScoreWidget::on_changeBtn_clicked()
{
    auto modelIndex = selectionModel->currentIndex();
    if (!modelIndex.isValid()) {
        return;
    }
    scoreChangeDialog->setModal(false);
    scoreChangeDialog->show();
    changeRow(modelIndex, modelIndex);
}


void ScoreWidget::on_refreshBtn_clicked()
{
    updateModel();
}

void ScoreWidget::changeRow(const QModelIndex &current, const QModelIndex &previous) {
    Q_UNUSED(previous);
    if (scoreChangeDialog->isHidden()) {
        return;
    }
    scoreChangeDialog->setName(model->data(model->index(current.row(), record.indexOf("name"))).toString());
    scoreChangeDialog->setStudentId(model->data(model->index(current.row(), record.indexOf("id"))).toString());
    scoreChangeDialog->setId(model->data(model->index(current.row(), record.indexOf("stu_id"))).toInt());

}

