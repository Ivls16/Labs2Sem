#include "order.h"

Order::Order(): startTime(0), finishTime(0), orderId(0), mass(0), address("") {}

Order::Order(QString id, QString name, QString tin, QString tout, QString mass):
    startTime(tin.toInt() / 60), finishTime(tout.toInt() % 60), orderId(id.toInt()), mass(mass.toInt()), address(name)
{}

Order::Order(int id, QString name, std::chrono::minutes tin, std::chrono::minutes tout, int mass):
    startTime(tin), finishTime(tout), orderId(id), mass(mass), address(name)
{}

void Order::Setup(Order other) {
    orderId = other.orderId;
    startTime = other.startTime;
    finishTime = other.finishTime;
    mass = other.mass;
    address = other.address;
}

std::pair<std::chrono::minutes, std::chrono::minutes> Order::TimeInterval() {
    return {startTime, finishTime};
}

int Order::ID() {
    return orderId;
}

QString Extended(QString q) {
    if (q.size() < 2) {
        q = "0" + q;
    }
    return q;
}

QString TimeIntervalString(QString tin, QString tout) {
    QString interval = "";
    int sin = tin.toInt(), sout = tout.toInt();
    interval += Extended(QString::number(sin / 60)) + ":" + Extended(QString::number(sin % 60));
    interval += "-";
    interval += Extended(QString::number(sout / 60)) + ":" + Extended(QString::number(sout % 60));
    return interval;
}

QString Order::Show() {
    QString result = "";
    result += "ID: " + QString::number(orderId) + " | address: " + address + " | time interval: ";
    result += TimeIntervalString(QString::number(startTime.count()), QString::number(finishTime.count()));
    result += " | mass: " + QString::number(mass);
    return result;
}

int Order::GetMass() {
    return mass;
}
