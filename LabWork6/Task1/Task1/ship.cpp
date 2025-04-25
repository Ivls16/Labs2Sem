#include "ship.h"

Ship::Ship() {

}

Ship::Ship(int id_, char name_[20], char type_, bool passenger_, double power_, int details_[5]) {
    id = id_;
    memcpy(name, name_, 20);
    type = type_;
    passenger = passenger_;
    power = power_;
    memcpy(details, details_, 5 * sizeof(int));
}

QString Ship::intArrayToString(const int arr[5]) const {
    QStringList list;
    for (int i = 0; i < 5; ++i) {
        list << QString::number(arr[i]);
    }
    return list.join(",");
}

QString Ship::display() const {
    QStringList ship({QString::number(id), name, QString(type), QString::number(passenger), QString::number(power), intArrayToString(details)});
    return ship.join("|");
}
