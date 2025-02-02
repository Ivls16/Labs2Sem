#include "courier.h"
#include "order.h"
#include <QPushButton>
#include <QListWidget>
#include <QComboBox>

class Matching: public QObject
{
Q_OBJECT
private:
    QComboBox *box;
    std::vector<Courier> *couriers;
    std::vector<Order> *orders;
    QPushButton *showCourierButton, *showImpossibleOrdersButton;
    QListWidget *showCourierInfo, *showImpossibleOrdersInfo;
    std::vector<std::pair<Courier, Order>> match;
    std::vector<Order> unpairedOrders;

    void ResetOrders();
public:
    Matching();
    Matching(QComboBox*, std::vector<Courier>*, std::vector<Order>*, QPushButton*, QPushButton*, QListWidget*, QListWidget*);
private slots:
    void ShowCourier();
    void ShowImpossibleOrders();
};
