#include "properties.h"
#include <QFile>
#include <utility>
#include <QTextStream>


Properties::Properties(QString path): path_(std::move(path)) {
}


QString Properties::get(const QString &key) {
    if (!prop_.contains(key)) {
        return "";
    }
    return prop_.value(key);
}

bool Properties::exist() {
    return QFile::exists(path_);
}

void Properties::load() {
    if (!exist()) {
        throw std::runtime_error("file not exists");
    }

    QFile file(path_);
    file.open(QIODeviceBase::ReadOnly | QIODeviceBase::Text);
    QTextStream textStream(&file);

    QString str;
    while (!textStream.atEnd()) {
        textStream >> str;
        auto strList = str.remove(" ").split("=");
        if (strList.size() < 2) break;
        prop_.insert(strList[0], strList[1]);
    }
    file.close();
}

void Properties::write() {
    QFile file(path_);
    file.open(QIODeviceBase::WriteOnly, QIODeviceBase::Truncate);
    QTextStream textStream(&file);
    for (const auto &item: prop_.asKeyValueRange()) {
        textStream << QString("%1=%2").arg(item.first, item.second);
    }
    file.close();

}
