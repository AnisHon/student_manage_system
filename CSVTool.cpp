//
// Created by Anis Han on 2024/4/2.
//

#include "CSVTool.h"
#include <QFileInfo>

CSVTool::CSVTool(const QString &path) {
    isValidate_ = false;
    path_ = path;
    if (!path.endsWith(".csv")) {
        throw std::runtime_error("不支持的文件类型");
    }
    QFile file(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (file.exists()) {

        QTextStream stream(&file);
        auto temp = stream.readLine().split(",", Qt::SkipEmptyParts);
        if (temp.empty()) {
            return;
        }
        headers_ = temp;
        isValidate_ = true;
    }
    file.close();
}

const QStringList &CSVTool::getHeader() const {
    return headers_;
}

bool CSVTool::isReadable() const {
    return isValidate_;
}

QVector<QStringList> CSVTool::readContent(const QVector<int> &ignoreColumn) {
    if (!isValidate_) {
        throw std::runtime_error("不能读取");
    }
    QFile file(path_);
    if (!file.exists()) {
        throw std::runtime_error("文件不存在");
    }
    QVector<QStringList> content;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream textStream(&file);
    textStream.setEncoding(QStringConverter::Utf8);


    textStream.readLine();
    while (!textStream.atEnd()) {
        content.append(textStream.readLine().split(","));
    }

    file.close();
    return content;
}

bool CSVTool::writeContent(const QVector<QStringList> &content) {

//    if (isValidate_ && content.size() != headers_.size()) {
//        throw std::runtime_error("列不必配");
//    }

    QSaveFile file(path_);
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);

    for (auto &column: headers_) {
        if (column.contains(",")) {
            column = QString("\"%1\"").arg(column);
        }
    }
    file.write(headers_.join(",").toUtf8());
    file.write("\n");
    for (auto &row: const_cast<QVector<QStringList>&>(content)) {
        for (auto &column: row) {
            if (column.contains(",")) {
                column = QString("\"%1\"").arg(column);
            }
        }
        file.write(row.join(",").toUtf8());
        file.write("\n");
    }


    file.commit();
    return true;
}

void CSVTool::setHeader(const QStringList &headers) {
    headers_ = headers;
    isValidate_ = true;
}
