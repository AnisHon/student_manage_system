//
// Created by Anis Han on 2024/4/12.
//

#include "LimitedQSqlTableModel.h"
LimitedQSqlTableModel::LimitedQSqlTableModel(QObject *parent):QSqlTableModel(parent) {

}

void LimitedQSqlTableModel::setLimit(int page, int total) {
    limit = QString("limit %1, %2").arg((page - 1) * total).arg(total);
    this->selectStatement();
}

QString LimitedQSqlTableModel::selectStatement() const {
    QString strSql = QSqlTableModel::selectStatement();
    strSql += " " + limit;
    return strSql;
}
