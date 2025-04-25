#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ship.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* = nullptr);
    ~MainWindow();

    void displayShip(Ship&);

private slots:
    void on_explicitCreate_clicked();

    void on_separatelyCreate_clicked();

    void on_pointerCreate_clicked();

    void on_referenceCreate_clicked();

private:
    Ui::MainWindow *ui;

    void QStringToChar20(const QString&, char[20]);
    void QStringToIntArray(const QString&, int[5]);
};
#endif // MAINWINDOW_H
