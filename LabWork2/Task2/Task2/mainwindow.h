#pragma once

#include <QMainWindow>
#include <QToolBar>
#include <QActionGroup>
#include <QGraphicsScene>
#include <QSlider>
#include <QMouseEvent>

#include "mygraphicsview.h"
#include "figureinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QToolBar *toolBar;
    QActionGroup* actionGroup;
    QGraphicsScene* graphicsScene;
    MyGraphicsView* graphicsView;
};
