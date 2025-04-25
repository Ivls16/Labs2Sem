#ifndef SHIP_H
#define SHIP_H

#include <QString>
#include <QStringList>
#include <QVector>

struct Ship {
    bool passenger;
    char type;
    int id;
    double power;
    char name[20];
    int details[5];

    QString display() const {
        QStringList ship({QString::number(id), name, QString(type), QString::number(passenger), QString::number(power), intArrayToString(details)});
        return ship.join("|");
    }

    QString intArrayToString(const int arr[5]) const {
        QStringList list;
        for (int i = 0; i < 5; ++i) {
            list << QString::number(arr[i]);
        }
        return list.join(",");
    }
};

#endif // SHIP_H
