#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QStringListModel>
#include <random>
#include "queue.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonPush_clicked();
    void on_buttonPop_clicked();
    void on_buttonTask_clicked();
    void updateInfo();

private:
    Ui::MainWindow *ui;
    Queue queue;
};
#endif // MAINWINDOW_H
