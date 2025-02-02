#include "matching.h"

Matching::Matching() {}

Matching::Matching(QComboBox* box, std::vector<Courier> *couriers, std::vector<Order>* orders,
         QPushButton *showCourierButton, QPushButton *showImpossibleOrdersButton,
         QListWidget *showCourierInfo, QListWidget *showImpossibleOrdersInfo):
    box(box), couriers(couriers), orders(orders),
    showCourierButton(showCourierButton), showImpossibleOrdersButton(showImpossibleOrdersButton),
    showCourierInfo(showCourierInfo), showImpossibleOrdersInfo(showImpossibleOrdersInfo) {
    connect(showCourierButton, &QPushButton::clicked, this, &Matching::ShowCourier);
    connect(showImpossibleOrdersButton, &QPushButton::clicked, this, &Matching::ShowImpossibleOrders);
}

bool Intersect(std::pair<std::chrono::minutes, std::chrono::minutes> p1, std::pair<std::chrono::minutes, std::chrono::minutes> p2) {
    if (p1.first > p2.first) {
        std::swap(p1, p2);
    }
    return p2.first <= p1.second;
}

void Matching::ResetOrders() {
    match.clear();
    unpairedOrders.clear();
    for (auto order : *orders) {
        bool found = false;
        for (auto courier : *couriers) {
            if (Intersect(order.TimeInterval(), courier.TimeInterval()) && courier.GetCapacity() >= order.GetMass()) {
                found = true;
                match.push_back({courier, order});
                break;
            }
        }
        if (!found) {
            unpairedOrders.push_back(order);
        }
    }
}

void Matching::ShowCourier() {
    ResetOrders();
    int courierId = this->box->currentText().toInt();
    showCourierInfo->clear();
    for (auto [courier, order] : match) {
        if (courier.ID() == courierId) {
            showCourierInfo->addItem(order.Show());
        }
    }
}

void Matching::ShowImpossibleOrders() {
    ResetOrders();
    showImpossibleOrdersInfo->clear();
    for (auto order : unpairedOrders) {
        showImpossibleOrdersInfo->addItem(order.Show());
    }
}
