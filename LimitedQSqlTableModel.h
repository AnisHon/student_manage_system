//
// Created by Anis Han on 2024/4/12.
//

#ifndef STUDENT_MANAGE_SYSTEM_LIMITEDQSQLTABLEMODEL_H
#define STUDENT_MANAGE_SYSTEM_LIMITEDQSQLTABLEMODEL_H

#include <QSqlTableModel>

class LimitedQSqlTableModel: public QSqlTableModel{
    Q_OBJECT

public:
    explicit LimitedQSqlTableModel(QObject *parent = nullptr);

    void setLimit(int page, int total);

    virtual QString selectStatement() const;

private:
    QString limit;

};


#endif //STUDENT_MANAGE_SYSTEM_LIMITEDQSQLTABLEMODEL_H
