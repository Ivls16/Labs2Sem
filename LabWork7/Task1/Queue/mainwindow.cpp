#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->lineEditValue->setValidator(new QIntValidator(-999999, 999999, this));
    connect(&queue, &Queue::sizeChanged, this, &MainWindow::updateInfo);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_buttonPush_clicked() {
    if (ui->lineEditValue->text().length() == 0) {
        return;
    }
    queue.push(ui->lineEditValue->text().toInt());
    ui->lineEditValue->clear();
}

void MainWindow::on_buttonPop_clicked() {
    if (queue.empty()) {
        return;
    }
    queue.pop();
}

void MainWindow::updateInfo() {
    ui->labelSize->setText("Size: " + QString::number(queue.size()));
    ui->labelEmpty->setText("Empty: " + (queue.empty() ? QString("True") : QString("False")));
    ui->labelFront->setText("Front: " + (queue.empty() ? QString("-") : QString::number(queue.front())));
    ui->labelBack->setText("Back: " + (queue.empty() ? QString("-") : QString::number(queue.back())));
    ui->listQueue->clear();
    queue.displayToQListWidget(ui->listQueue);
}

void MainWindow::on_buttonTask_clicked() {
    std::mt19937 rnd(clock());
    Queue q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.push(rnd() % 50);
        q2.push(rnd() % 50);
    }
    QString text;
    text += "q1 : " + q1.str() + "\tq2 : " + q2.str();
    q1.insertAfterMax(&q2);
    text += "\nresult : " + q1.str();
    ui->textTask->setText(text);
}

