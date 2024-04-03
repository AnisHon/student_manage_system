//
// Created by Anis Han on 2024/4/2.
//

#ifndef STUDENT_MANAGE_SYSTEM_CSVTOOL_H
#define STUDENT_MANAGE_SYSTEM_CSVTOOL_H

#include <QFile>
#include <QTextStream>
#include <QSaveFile>
#include <QTextStream>

class CSVTool {

public:
    explicit CSVTool(const QString &path);

    const QStringList &getHeader() const;

    bool isReadable() const ;

    QVector<QStringList> readContent(const QVector<int> &ignoreColumn = QVector<int>());

    bool writeContent(const QVector<QVector<QString>> &content);

    void setHeader(const QStringList &headers);

private:
    QStringList headers_;
    QString path_;
    bool isValidate_;



};


#endif //STUDENT_MANAGE_SYSTEM_CSVTOOL_H
