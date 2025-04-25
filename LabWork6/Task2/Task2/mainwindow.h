#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEventLoop>
#include <QTimer>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "ship.h"

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

    void Cycling();
    int Input();
    void Quit();
    void ParagraphToFile();
    void FileToParagraph();
    void ArrayToFile();
    void FileToArray();
    void StructToFile();
    void FileToStruct();
    void StructToBinary();
    void BinaryToStruct();
    void ReadShip(Ship& ship, QTextStream& in);

private:
    Ui::MainWindow *ui;
    QEventLoop loop;

    inline static const QString surname = "СафоновЛаб20";
    inline static const QString paragraphFile = surname + "_0.txt";
    inline static const QString arrayFile = surname + "_1.txt";
    inline static const QString structFile = surname + "_2.txt";
    inline static const QString binaryFile = surname + "_3.bin";
};
#endif // MAINWINDOW_H
