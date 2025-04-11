#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QLayout>
#include "keyboard.h"

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
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_languageChangeComboBox_2_currentIndexChanged(int index);
    void on_stopButton_2_clicked();
    void on_startButton_2_clicked();
    void on_openTestButton_2_clicked();
private:
    Ui::MainWindow *ui;
    Keyboard* keyboard = new Keyboard(this);
    bool isTesting = false;
    QStringList currTest;
    int currLocal;
    QElapsedTimer* timer = new QElapsedTimer();
    QTimer* updateTimer = new QTimer();
    int words = 0;
    int correctSymbols = 0;
    int allSymbols = 0;
    int currNeededSimb = 0;
    int currTestNum = 0;

    void setButtons();
    void updateInfo();
    void workWithEvent(QKeyEvent*);
    void setText();
    bool checkTest();
};

#endif // MAINWINDOW_H
