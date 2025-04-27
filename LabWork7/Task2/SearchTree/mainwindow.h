#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "searchtree.h"

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
    void on_buttonAdd_clicked();
    void on_buttonDelete_clicked();
    void on_buttonFind_clicked();
    void on_buttonPreorder_clicked();
    void on_buttonPostorder_clicked();
    void on_buttonInorder_clicked();
    void on_buttonBalance_clicked();

private:
    Ui::MainWindow *ui;
    SearchTree *tree;

    void clearUi();
};

#endif // MAINWINDOW_H
