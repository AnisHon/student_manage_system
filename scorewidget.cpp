#include "scorewidget.h"
#include "ui_scorewidget.h"
#include "CSVTool.h"
#include <QSqlRecord>
#include <QSqlError>
#include <QFileDialog>
#include <QMessageBox>

ScoreWidget::ScoreWidget(const QSqlDatabase& database, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScoreWidget)
{
    ui->setupUi(this);
    db = database;

    ui->pageIndex->setMinimum(1);
    ui->pageIndex->setValue(1);
    ui->pageIndex->setMaximum(queryAllCount() / ROW_COUNT + 1);



    model = new QSqlTableModel(this);
    selectionModel = new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(selectionModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    scoreChangeDialog = new ScoreChangeDialog(this);




    initMenu();
    loadSubjects();
    initModel();


    connect(ui->tableView, &QTableView::customContextMenuRequested, this, &ScoreWidget::requestMenu);
    connect(selectionModel, &QItemSelectionModel::currentRowChanged, this, &ScoreWidget::changeRow);
}

ScoreWidget::~ScoreWidget()
{
    delete ui;
}

void ScoreWidget::initMenu() {
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    menu = new QMenu;
    menu->addAction(ui->changeAction);
    menu->addAction(ui->refreshAction);
    menu->addSeparator();
    menu->addAction(ui->inputAction);
    menu->addAction(ui->outputAction);
    menu->addAction(ui->outputAllAction);
}

QSqlQuery ScoreWidget::queryForScore() {
    QString mainSql = "select stu.id as stu_id, stu.student_id as id, stu.name as name, %1 sum(score.score) as 总分, avg(score.score) as 平均分 from score "
                      "left join student stu on score.stu_id = stu.id "
                      "left join subject on score.subject_id = subject.id";

    QString conditionalAggregation = "MAX(case when score.subject_id = %1 then score.score end) as %2,";
    QString aggregation;

    for (const auto &item: subjects.asKeyValueRange()) {
        aggregation += QString(conditionalAggregation).arg(item.first).arg(item.second);

    }
    mainSql = mainSql.arg(aggregation);


    if (!filter.isEmpty()) {
        mainSql += " where " + filter;
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




    QSqlQuery query(mainSql + QString(" limit %1, %2").arg((currentIndex - 1) * ROW_COUNT).arg(ROW_COUNT));

//    qDebug() << (mainSql + QString(" limit %1, %2").arg((currentIndex - 1) * ROW_COUNT).arg(ROW_COUNT));
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
//    model->setHeaderData(record.indexOf("total"), Qt::Horizontal, "总分");
//    model->setHeaderData(record.indexOf("average"), Qt::Horizontal, "平均分");
//    model->setSort(model->fieldIndex("average"), Qt::DescendingOrder);
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
//    qDebug() << ui->sortColumn->currentData().toInt();
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

//    qDebug() << model->lastError().text();
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
    ui->pageIndex->setMinimum(1);
    ui->pageIndex->setValue(currentIndex);
    ui->pageIndex->setMaximum(queryAllCount() / ROW_COUNT + 1);
    currentIndex = ui->pageIndex->value();
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



void ScoreWidget::on_inputAction_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "导入CSV", QDir::homePath(), "CSV文件(*.csv)");
    try {
        CSVTool tool(path);
        headerValidate(tool);

        const QStringList &header = tool.getHeader();
        auto mapping = mappingHeader(header);
        int index = header.indexOf("学号");

        auto content = tool.readContent();

        for (const auto &item: content) {
            int stu_id = getStudentId(item[index]);
            if (stu_id == -1) {
                continue;
            }
            insertScore(stu_id, item, mapping);

        }


    } catch (std::runtime_error &error) {
        QMessageBox::warning(this, "错误", error.what());
    }






}


void ScoreWidget::on_outputAction_triggered()
{

    QString path = QFileDialog::getSaveFileName(this, "导出表", QDir::homePath(), "csv(*.csv)");
    if (path.isEmpty()) {
        return;
    }
    QStringList header;

    for (int i = 1; i < model->columnCount(); ++i) {
        header << model->headerData(i, Qt::Horizontal).toString();
    }

//    qDebug() << header;
//    qDebug() << path;
    QVector<QStringList> content;
    for (int i = 0; i < model->rowCount(); ++i) {
        QStringList row;
        for (int j = 1; j < model->columnCount(); ++j) {

            auto data1 = model->data(model->index(i, j));
            row << (data1.isNull() ? "未选课" : data1.toString());

        }
        content << row;
    }



    try {
        CSVTool csvTool(path);
        csvTool.setHeader(header);
        csvTool.writeContent(content);

    } catch (std::runtime_error &err) {
//        qDebug() << path;
        QMessageBox::warning(this, "错误", err.what());
    }


}

void ScoreWidget::requestMenu(const QPoint &pos) {
    menu->exec(QCursor::pos());
}

void ScoreWidget::on_outputAllAction_triggered()
{

    QString path = QFileDialog::getSaveFileName(this, "导出表", QDir::homePath(), "csv(*.csv)");
    if (path.isEmpty()) {
        return;
    }

    QString mainSql = "select stu.id as stu_id, stu.student_id as id, stu.name as name, %1 sum(score.score) as 总分, avg(score.score) as 平均分 from score "
                      "left join student stu on score.stu_id = stu.id "
                      "left join subject on score.subject_id = subject.id";

    QString conditionalAggregation = "MAX(case when score.subject_id = %1 then score.score end) as %2,";
    QString aggregation;

    for (const auto &item: subjects.asKeyValueRange()) {
        aggregation += QString(conditionalAggregation).arg(item.first).arg(item.second);
    }
    mainSql = mainSql.arg(aggregation);
    mainSql += " group by stu_id";

    QSqlQuery query(mainSql);

    QStringList header;
    auto sqlRecord = query.record();
    for (int i = 1; i < sqlRecord.count(); ++i) {
        header << sqlRecord.fieldName(i);
    }

//    qDebug() << header;
//    qDebug() << path;
    QVector<QStringList> content;
    while (query.next()) {
        QStringList row;
        for (int j = 1; j < sqlRecord.count(); ++j) {
            auto data1 = query.value(j);
            row << (data1.isNull() ? "未选课" : data1.toString());
        }
        content << row;
    }
    try {
        CSVTool csvTool(path);
        csvTool.setHeader(header);
        csvTool.writeContent(content);

    } catch (std::runtime_error &err) {
//        qDebug() << path;
        QMessageBox::warning(this, "错误", err.what());
    }



}

void ScoreWidget::headerValidate(const CSVTool& tool) {
    const QStringList &header = tool.getHeader();
    if (header.isEmpty()) {
        throw std::runtime_error("文件格式错误");
    }
    if (!header.contains("学号")) {
        throw std::runtime_error("缺少学号，必须有学号作为学生身份唯一索引");
    }
}


QMap<int, int> ScoreWidget::mappingHeader(const QStringList& headers) {
    QMap<int, int> map;

    QSqlQuery query;
    query.prepare("select id from subject where name = :name");

    for (int i = 0; i < headers.size(); ++i) {
        query.bindValue(":name", headers[i]);
        query.exec();
        query.next();
//        qDebug() << query.lastError();
        if (query.isNull(0)) {
            continue;
        }
        map.insert(i, query.value(0).toInt());
    }
    return map;
}

int ScoreWidget::getStudentId(const QString& studentId) {
    QSqlQuery query;
    query.setForwardOnly(true);
    query.prepare("select id from student where student_id = :student_id");
    query.bindValue(":student_id", studentId);
    query.exec();
    query.next();
    if (query.isNull(0)) {
        return -1;
    }

    return query.value(0).toInt();
}

bool ScoreWidget::validateScore(const QString& str) {
    bool isNum;
    int temp = str.toInt(&isNum);
    return 0<= temp && temp <= 100 && isNum;
}

void ScoreWidget::insertScore(int student_id, const QStringList &scores, const QMap<int, int> &map) {
    QSqlQuery insertQuery;
    QSqlQuery existQuery;
    QSqlQuery updateQuery;

    insertQuery.prepare("insert into score(stu_id, subject_id, score) value(:stu_id, :sub_id, :score)");
    existQuery.prepare("select count(*) from score where subject_id = :subject_id and stu_id = :stu_id");
    updateQuery.prepare("update score set score = :score where subject_id = :subject_id and stu_id = :stu_id");
    for (const auto &item: map.asKeyValueRange()) {
        if (!validateScore(scores[item.first])) {
            continue;
        }
        existQuery.bindValue(":stu_id", student_id);
        existQuery.bindValue(":subject_id", item.second);
        existQuery.exec();
        existQuery.next();
//        qDebug() << existQuery.value(0).toInt();
//        qDebug() << existQuery.lastError().text();
        if (existQuery.value(0).toInt() == 0) {
            insertQuery.bindValue(":stu_id", student_id);
            insertQuery.bindValue(":sub_id", item.second);
            insertQuery.bindValue(":score", scores[item.first].toInt());
            insertQuery.exec();
//            qDebug() << insertQuery.lastError().text();
        } else {
            updateQuery.bindValue(":stu_id", student_id);
            updateQuery.bindValue(":sub_id", item.second);
            updateQuery.bindValue(":score", scores[item.first].toInt());
            updateQuery.exec();
//            qDebug() << existQuery.lastError().text();
        }

    }

}




void ScoreWidget::on_pageIndex_editingFinished()
{
    currentIndex = ui->pageIndex->value();
    updateModel();
//    qDebug() << model->lastError().text();
}

int ScoreWidget::queryAllCount() {
    QSqlQuery query;
    query.exec("select count(*) from student");
    query.next();
    return query.value(0).toInt();
}
