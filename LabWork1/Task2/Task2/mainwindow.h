#pragma once

#include "matching.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Database;

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<Courier> *GetCourierArray();
    std::vector<Order> *GetOrderArray();
    QComboBox* ComboBox();

private:
    std::vector<Courier> courierArray;
    std::vector<Order> orderArray;
    Ui::MainWindow *ui;
    Database *courierList, *orderList;
    Matching* matching;
};
