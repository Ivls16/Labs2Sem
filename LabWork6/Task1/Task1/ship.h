#ifndef SHIP_H
#define SHIP_H

#include <QString>
#include <QStringList>
#include <QVector>

struct Ship {
    Ship();
    Ship(int, char[20], char, bool, double, int[5]);

    bool passenger;
    char type;
    int id;
    double power;
    char name[20];
    int details[5];

    QString display() const;
    QString intArrayToString(const int arr[5]) const;
};

#endif // SHIP_H
