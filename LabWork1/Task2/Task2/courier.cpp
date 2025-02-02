#include "courier.h"

Courier::Courier(): startTime(0), finishTime(0), courierId(0), carCapacity(0), name("") {}

Courier::Courier(QString id, QString name, QString tin, QString tout, QString mass):
    startTime(tin.toInt() / 60), finishTime(tout.toInt() % 60), courierId(id.toInt()), carCapacity(mass.toInt()), name(name)
{}

Courier::Courier(int id, QString name, std::chrono::minutes tin, std::chrono::minutes tout, int mass):
    startTime(tin), finishTime(tout), courierId(id), carCapacity(mass), name(name)
{}

void Courier::Setup(Courier other) {
    courierId = other.courierId;
    startTime = other.startTime;
    finishTime = other.finishTime;
    carCapacity = other.carCapacity;
    name = other.name;
}

std::pair<std::chrono::minutes, std::chrono::minutes> Courier::TimeInterval() {
    return {startTime, finishTime};
}

int Courier::ID() {
    return courierId;
}

int Courier::GetCapacity() {
    return carCapacity;
}
