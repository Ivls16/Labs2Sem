#pragma once
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QItemDelegate>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *warningBox;
    QTableWidget *table;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

    void SetWarning(bool, QString);

private slots:
    void on_resetTable_clicked(bool=false);
    void on_tableWidget_itemChanged(QTableWidgetItem *item);
    void on_nextDay_clicked();
    void on_previousDay_clicked();
    void on_duration_clicked();
    void on_daysTillYourBirthday_clicked();
    void on_weekNumber_clicked();
    void on_isLeap_clicked();
    void on_date_editingFinished();
    void on_date_textEdited();
    void on_addDate_clicked();
};
