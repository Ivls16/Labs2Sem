#include <QString>
#include <chrono>

class Courier {
private:
    std::chrono::minutes startTime, finishTime;
    int courierId, carCapacity;
    QString name;
public:
    Courier();
    Courier(QString, QString, QString, QString, QString);
    Courier(int, QString, std::chrono::minutes, std::chrono::minutes, int);

    void Setup(Courier);
    std::pair<std::chrono::minutes, std::chrono::minutes> TimeInterval();
    int ID();
    int GetCapacity();
};
