#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    toolBar = addToolBar("Toolbar");

    setMouseTracking(true);

    QAction* line = toolBar->addAction(QIcon("icons/line.png"), "Прямая"); line->setCheckable(true);
    QAction* triangle = toolBar->addAction(QIcon("icons/triangle.png"), "Треугольник"); triangle->setCheckable(true);
    QAction* circle = toolBar->addAction(QIcon("icons/circle.png"), "Круг"); circle->setCheckable(true);
    QAction* rhombus = toolBar->addAction(QIcon("icons/rhombus.png"), "Ромб"); rhombus->setCheckable(true);
    QAction* square = toolBar->addAction(QIcon("icons/square.png"), "Квадрат"); square->setCheckable(true);
    QAction* rectangle = toolBar->addAction(QIcon("icons/rectangle.png"), "Прямоугольник"); rectangle->setCheckable(true);
    QAction* fiveStar = toolBar->addAction(QIcon("icons/fiveStar.png"), "Пятиконечная звезда"); fiveStar->setCheckable(true);
    QAction* sixStar = toolBar->addAction(QIcon("icons/sixStar.png"), "Шестиконечная звезда"); sixStar->setCheckable(true);
    QAction* eightStar = toolBar->addAction(QIcon("icons/eightStar.png"), "Восьмиконечная звезда"); eightStar->setCheckable(true);
    QAction* hexagonal = toolBar->addAction(QIcon("icons/hexagonal.png"), "Шестиугольник"); hexagonal->setCheckable(true);
    QAction* cross = toolBar->addAction(QIcon("icons/cross.png"), "Крестик"); cross->setCheckable(true);
    QAction* zero = toolBar->addAction(QIcon("icons/question.png"), "Не фигура"); zero->setCheckable(true);

    actionGroup = new QActionGroup(this);
    actionGroup->setExclusive(true);

    actionGroup->addAction(line);
    actionGroup->addAction(triangle);
    actionGroup->addAction(circle);
    actionGroup->addAction(rhombus);
    actionGroup->addAction(square);
    actionGroup->addAction(rectangle);
    actionGroup->addAction(fiveStar);
    actionGroup->addAction(sixStar);
    actionGroup->addAction(eightStar);
    actionGroup->addAction(hexagonal);
    actionGroup->addAction(cross);
    actionGroup->addAction(zero);

    line->setChecked(true);

    graphicsScene = new QGraphicsScene(this);
    graphicsScene->setSceneRect(0, 0, 1060, 650);
    graphicsScene->setFocusOnTouch(true);

    graphicsView = new MyGraphicsView(actionGroup, this, this);
    graphicsView->setGeometry(15, 45, 1060, 650);
    graphicsView->setScene(graphicsScene);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}
