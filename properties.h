#ifndef PROPERITIES_H
#define PROPERITIES_H

#include <QMap>

class Properties
{
public:
    explicit Properties(QString path);


    QString get(const QString &key);

    bool exist();

    void load();

    void write();

private:
    QMap<QString, QString> prop_;
    QString path_;

};

#endif // PROPERITIES_H
