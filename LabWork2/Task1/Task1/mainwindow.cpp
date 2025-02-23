#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(mainWidget);
    rect = new Ride(ui->horizontalSlider, this);
    layout->addWidget(ui->horizontalSlider);
    layout->addWidget(rect);
    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete rect;
    delete ui;
}

