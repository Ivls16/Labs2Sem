#include <QString>
#include <chrono>

class Order {
private:
    std::chrono::minutes startTime, finishTime;
    int orderId, mass;
    QString address;
public:
    Order();
    Order(QString, QString, QString, QString, QString);
    Order(int, QString, std::chrono::minutes, std::chrono::minutes, int);

    void Setup(Order);
    std::pair<std::chrono::minutes, std::chrono::minutes> TimeInterval();
    int ID();
    QString Show();
    int GetMass();
};
