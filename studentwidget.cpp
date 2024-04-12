#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
#include <QFileInfo>
#include <QPixmap>
#include <QFileDialog>
#include <QSqlQuery>
#include "studentwidget.h"
#include "ui_studentwidget.h"
#include "aligncenterdelegate.h"

StudentWidget::StudentWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentWidget)
{
    ui->setupUi(this);

    ui->ageBox->setSuffix("岁");
    comboBoxDelegate = new ComboBoxDelegate({"男", "女"});


    auto geometry =ui->pictureLabel->geometry();
    geometry.setHeight(geometry.width());
    ui->pictureLabel->setGeometry(geometry);

    initTable();
    initMenu();
    initLimitPage();
}

StudentWidget::~StudentWidget()
{
    delete ui;
}

void StudentWidget::initMenu() {
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    this->menu = new QMenu(this);
    this->menu->addAction(ui->insert);
    this->menu->addAction(ui->deleteStu);
    this->menu->addAction(ui->commit);
    this->menu->addAction(ui->rollback);
}

void StudentWidget::initTable() {
    ui->tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setAlternatingRowColors(true);

    model = new LimitedQSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setSort(model->fieldIndex("id"), Qt::AscendingOrder);
    model->select();
    model->setHeaderData(model->fieldIndex("id"), Qt::Horizontal, "表ID");
    model->setHeaderData(model->fieldIndex("student_id"), Qt::Horizontal, "学号");
    model->setHeaderData(model->fieldIndex("name"), Qt::Horizontal, "姓名");
    model->setHeaderData(model->fieldIndex("gender"), Qt::Horizontal, "性别");
    model->setHeaderData(model->fieldIndex("age"), Qt::Horizontal, "年龄");
    model->setHeaderData(model->fieldIndex("address"), Qt::Horizontal, "住址");


    selectionModel = new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(selectionModel);
    ui->tableView->setItemDelegateForColumn(model->fieldIndex("gender"), comboBoxDelegate);

    ui->tableView->setColumnHidden(model->fieldIndex("portrait"), true);

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(ui->studentIdInput, model->fieldIndex("student_id"));
    mapper->addMapping(ui->nameInput, model->fieldIndex("name"));
    mapper->addMapping(ui->genderBox, model->fieldIndex("gender"));
    mapper->addMapping(ui->ageBox, model->fieldIndex("age"));
    mapper->addMapping(ui->addressInput, model->fieldIndex("address"));
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
//    mapper->setItemDelegate(comboBoxDelegate);

//    model->setData(model->index(0, model->fieldIndex("gender")), "F", Qt::EditRole);


    mapper->toFirst();



    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);


//    limit = "limit 0, 20";
//    model->setFilter(limit);
//    model->select();

    connect(mapper, &QDataWidgetMapper::currentIndexChanged, this, &StudentWidget::mappingRowChanged);
    connect(selectionModel, &QItemSelectionModel::currentRowChanged, this, &StudentWidget::changeMappingRow);

}

void StudentWidget::changeMappingRow(const QModelIndex &current, const QModelIndex &previous) {
    Q_UNUSED(previous);
    if (!current.isValid()) {
        ui->nameInput->setText("");
        ui->ageBox->setValue(0);
        ui->studentIdInput->setText("");
        ui->addressInput->setText("");
        
        return;
    }
    mapper->setCurrentIndex(current.row());



}

void StudentWidget::on_genderBox_currentTextChanged(const QString &arg1)
{
    model->setData(model->index(mapper->currentIndex(), model->fieldIndex("gender")), arg1, Qt::EditRole);
}


void StudentWidget::on_searchEdit_editingFinished()
{
    on_searchEdit_textChanged(ui->searchEdit->text());
}


void StudentWidget::on_searchEdit_textChanged(const QString &arg1)
{
    switch (ui->searchMethod->currentIndex()) {
        case NAME:
            searchFilter = QString("name like '%%1%'").arg(ui->searchEdit->text());
            break;
        case ID:
            searchFilter = QString("student_id like '%%1%'").arg(ui->searchEdit->text());
            break;
    }
    initLimitPage();
    filterChange();

}


void StudentWidget::on_searchMethod_currentIndexChanged(int index)
{
    on_searchEdit_textChanged(ui->searchEdit->text());
}


void StudentWidget::on_addStudent_clicked()
{
    QSqlRecord record = model->record();
    record.setNull(model->fieldIndex("id"));
    record.setValue(model->fieldIndex("name"), "新学生");
    record.setValue(model->fieldIndex("age"), 0);
    record.setValue(model->fieldIndex("gender"), "男");
    record.setValue(model->fieldIndex("address"), "新地址");
    model->insertRecord(model->rowCount(), record);
}


void StudentWidget::on_deleteStudent_clicked()
{
    if (!ui->tableView->currentIndex().isValid()) {
        QMessageBox::warning(this, "错误", "请选择一项后点击删除");
        return;
    }

    QString name = model->data(model->index(ui->tableView->currentIndex().row(), model->fieldIndex("name")), Qt::EditRole).toString();
    QString student_id = model->data(model->index(ui->tableView->currentIndex().row(), model->fieldIndex("student_id")), Qt::EditRole).toString();
    QString msg = QString("你确定要删除%1(学号：%2)吗？\n在提交之前可以回滚所有删除").arg(name, student_id);
    auto result = QMessageBox::information(this, "删除操作",msg, QMessageBox::Yes, QMessageBox::No);


    if (result == QMessageBox::Yes) {
        int row = selectionModel->currentIndex().row();
        ui->tableView->setRowHidden(row, true);
        model->removeRow(row);

//        qDebug() << selectionModel->currentIndex().row();
    }

}

bool StudentWidget::changePage() {
    if (!model->isDirty()) {
        return true;
    }

    auto result = QMessageBox::question(this, "退出", "改变项尚未保存，您是否要退出该页？");

    return result == QMessageBox::StandardButton::Yes;
}

void StudentWidget::on_submitBtn_clicked()
{
    if (!model->isDirty()) {
        QMessageBox::warning(this,"未发生更改","您未做任何更改，无需提交");
        return;
    }

    if (!model->submitAll()) {
        QMessageBox::critical(this, "发生错误", QString("错误如下：%1\n请检查表单").arg(model->lastError().text()));
    } else {
        model->select();
    }

}


void StudentWidget::on_pushButton_clicked()
{
    if (!model->isDirty()) {
        QMessageBox::warning(this,"未发生更改","您未做任何更改，无需回滚");
        return;
    }
    model->revertAll();
    for (int i = 0; i < model->rowCount(); ++i) {
        ui->tableView->setRowHidden(i, false);
    }

}


void StudentWidget::on_pushButton_2_clicked()
{
    auto modelIndex = selectionModel->currentIndex();
    if (!modelIndex.isValid()) {
        return;
    }
    QString filename = QFileDialog::getOpenFileName(this, "选择图片", QDir::homePath(), "图片文件(*.jpg *.png *.jpeg)");
    QFileInfo info(filename);

    if (!info.exists()) {
        QMessageBox::warning(this, "文件不存在", "该文件不存在，请选择新文件");
        return;
    }
    auto portrait = model->data(model->index(modelIndex.row(), model->fieldIndex("portrait")), Qt::EditRole);
    if (!portrait.isNull()) {
        QFile::moveToTrash(base_path + portrait.toString());
    }

    QString newFileName = model->data(model->index(modelIndex.row(), model->fieldIndex("student_id"))).toString()
            + "."
            + info.suffix();

    QFile::copy(filename, base_path + newFileName);
    filename = base_path + newFileName;

    model->setData(model->index(modelIndex.row(), model->fieldIndex("portrait")), newFileName);

    QPixmap pixel(filename);
    pixel = pixel.scaledToHeight(200).scaledToWidth(200);
    ui->pictureLabel->setPixmap(pixel);

}

void StudentWidget::mappingRowChanged(int index) {
    QString portrait_path;
    auto portrait = model->data(model->index(index, model->fieldIndex("portrait")), Qt::EditRole);

    portrait_path = base_path + (portrait.isNull() ? default_portrait : portrait.toString());
    QFileInfo file(portrait_path);
    if (!file.exists()) {
        portrait_path = base_path + default_portrait;
    }
    QPixmap pixel(portrait_path);
    pixel = pixel.scaled(200, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->pictureLabel->setPixmap(pixel);
}

int StudentWidget::queryAllCount() {
    QSqlQuery query;
    QString sql = "select count(*) from student" + (searchFilter.isEmpty() ? "": " where " + searchFilter);
//    qDebug() << sql;
    query.exec(sql);
    query.next();
//    qDebug() << query.lastError().text();
    return query.value(0).toInt();
}

//void StudentWidget::on_pageSpan_valueChanged(int arg1)
//{
//    limit = QString("limit %1, %2")
//}


void StudentWidget::on_tableView_customContextMenuRequested(const QPoint &pos)
{
    this->menu->exec(QCursor::pos());
}


void StudentWidget::on_pageNumber_valueChanged(int arg1)
{
    model->setLimit(arg1, PAGE_COUNT);
    filterChange();
}

void StudentWidget::initLimitPage() {
    int total = queryAllCount();
    if (total == 0) {
        return;
    }
    ui->pageNumber->setMinimum(1);
    ui->pageNumber->setMaximum(total / PAGE_COUNT + 1);
    ui->pageNumber->setValue(1);
    model->setLimit(1, PAGE_COUNT);
}

void StudentWidget::filterChange() {
    model->setFilter(searchFilter);
    model->select();
}

