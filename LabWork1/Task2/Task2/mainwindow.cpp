#include "ui_mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    courierList = new Database(this, false, ui->label, "Список курьеров", ui->tableWidget_2, QStringList({"ID", "ФИО", "Время", "Подъемность"}), ui->pushButton_8, ui->pushButton_10, ui->pushButton_4, ui->pushButton_5);
    orderList = new Database(this, true, ui->label_2, "Список заказов", ui->tableWidget, QStringList({"ID", "Товар", "Время", "Вес"}), ui->pushButton_9, ui->pushButton_11, ui->pushButton_6, ui->pushButton_7);
    matching = new Matching(ui->comboBox, &courierArray, &orderArray, ui->pushButton_3, ui->pushButton_2, ui->listWidget, ui->listWidget_2);
}

std::vector<Courier>* MainWindow::GetCourierArray() {
    return &courierArray;
};

std::vector<Order>* MainWindow::GetOrderArray() {
    return &orderArray;
}

MainWindow::~MainWindow() {
    delete ui;
}

QComboBox* MainWindow::ComboBox() {
    return ui->comboBox;
}

