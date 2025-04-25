#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Korabliki");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayShip(Ship& ship) {
    ui->shipLabel->setText(ship.display());
}

void MainWindow::QStringToChar20(const QString& input, char out[20]) {
    QByteArray temp = input.toLatin1();
    std::strncpy(out, temp.constData(), 19);
    out[19] = '\0';
}

void MainWindow::QStringToIntArray(const QString& input, int out[5]) {
    QStringList parts = input.split(' ', Qt::SkipEmptyParts);
    for (int i = 0; i < 5; ++i) {
        bool ok = false;
        out[i] = parts[i].toInt(&ok);
    }
}

void MainWindow::on_explicitCreate_clicked() {
    char name[20];
    QStringToChar20(ui->nameLine->text(), name);
    int details[5];
    QStringToIntArray(ui->detailsLine->text(), details);

    Ship ship(ui->idLine->text().toInt(),
              name,
              ui->typeLine->text().toLatin1().at(0),
              (bool)ui->passengerLine->text().toInt(),
              ui->powerLine->text().toDouble(),
              details);

    displayShip(ship);
}


void MainWindow::on_separatelyCreate_clicked() {
    char name[20];
    QStringToChar20(ui->nameLine->text(), name);
    int details[5];
    QStringToIntArray(ui->detailsLine->text(), details);

    Ship ship;
    ship.id = ui->idLine->text().toInt();
    memcpy(ship.name, name, 20);
    ship.type = ui->typeLine->text().toLatin1().at(0);
    ship.passenger = (bool)ui->passengerLine->text().toInt();
    ship.power = ui->powerLine->text().toDouble();
    memcpy(ship.details, details, 5 * sizeof(int));

    displayShip(ship);
}


void MainWindow::on_pointerCreate_clicked() {
    char name[20];
    QStringToChar20(ui->nameLine->text(), name);
    int details[5];
    QStringToIntArray(ui->detailsLine->text(), details);

    Ship* ship = new Ship();
    ship->id = ui->idLine->text().toInt();
    memcpy(ship->name, name, 20);
    ship->type = ui->typeLine->text().toLatin1().at(0);
    ship->passenger = (bool)ui->passengerLine->text().toInt();
    ship->power = ui->powerLine->text().toDouble();
    memcpy(ship->details, details, 5 * sizeof(int));

    displayShip(*ship);
}


void MainWindow::on_referenceCreate_clicked() {
    char name[20];
    QStringToChar20(ui->nameLine->text(), name);
    int details[5];
    QStringToIntArray(ui->detailsLine->text(), details);

    Ship ship;
    Ship& rship = ship;

    rship.id = ui->idLine->text().toInt();
    memcpy(rship.name, name, 20);
    rship.type = ui->typeLine->text().toLatin1().at(0);
    rship.passenger = (bool)ui->passengerLine->text().toInt();
    rship.power = ui->powerLine->text().toDouble();
    memcpy(rship.details, details, 5 * sizeof(int));

    displayShip(rship);
}

