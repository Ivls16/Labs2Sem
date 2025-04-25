#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, &loop, &QEventLoop::quit);
    QTimer::singleShot(50, [&]{
        Cycling();
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::ReadShip(Ship& ship, QTextStream& in) {
    in >> ship.id >> ship.name;
    if (strlen(ship.name) == 0) {
        return;
    }
    QString temps;
    in >> temps;
    ship.type = temps.at(0).toLatin1();
    int tempi;
    in >> tempi;
    ship.passenger = tempi;
    in >> ship.power;
    for (int i = 0; i < 5; i++) {
        in >> ship.details[i];
    }
}

int MainWindow::Input() {
    loop.exec();
    return ui->comboBox->currentIndex();
}

void MainWindow::Quit() {
    QCoreApplication::quit();
}

void MainWindow::ParagraphToFile() {
    QString paragraph = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    QFile file(paragraphFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "error" << file.errorString();
        return;
    }
    QTextStream out(&file);
    for (auto ch : paragraph) {
        out << ch;
    }
    file.close();
    QMessageBox::information(this, "info", "Абзац успешно записан");
}

void MainWindow::FileToParagraph() {
    QFile file(paragraphFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error" << file.errorString();
        ui->textOutput->clear();
        QMessageBox::critical(this, "error", "Файл не найден");
        return;
    }
    QTextStream in(&file);
    QString res;
    while (!in.atEnd()) {
        QChar ch;
        in >> ch;
        res += ch;
    }
    file.close();
    ui->textOutput->setText(res);
    QMessageBox::information(this, "info", "Абсолютный успех");
}

void MainWindow::ArrayToFile() {
    QStringList array = ui->textEdit->toPlainText().split(" ");
    ui->textEdit->clear();
    QFile file(arrayFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "error" << file.errorString();
        return;
    }
    QTextStream out(&file);
    out << array[0] << '\n';
    for (int i = 1; i < (int)array.size() - 1; i++) {
        out << array[i] << '-';
    }
    out << array[(int)array.size() - 1] << '\n';
    file.close();
    QMessageBox::information(this, "info", "Массив успешно записан");
}

void MainWindow::FileToArray() {
    QFile file(arrayFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error" << file.errorString();
        ui->textOutput->clear();
        QMessageBox::critical(this, "error", "Файл не найден");
        return;
    }
    QTextStream in(&file);
    ui->textOutput->clear();
    int n;
    in >> n;
    ui->textOutput->append(QString::number(n));
    QString arr;
    in >> arr;
    ui->textOutput->append(arr.split("-").join(" "));
    file.close();
    QMessageBox::information(this, "info", "Легендарно");
}

void MainWindow::StructToFile() {
    QString fields = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    QFile file(structFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        qDebug() << "error" << file.errorString();
        return;
    }
    QTextStream out(&file);
    out << fields << '\n';
    file.close();
    QMessageBox::information(this, "info", "Структура успешно добавлена");
}

void MainWindow::FileToStruct() {
    QFile file(structFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "error" << file.errorString();
        ui->textOutput->clear();
        QMessageBox::critical(this, "error", "Файл не найден");
        return;
    }
    QTextStream in(&file);
    ui->textOutput->clear();
    while (!in.atEnd()) {
        Ship ship;
        ReadShip(ship, in);
        if (strlen(ship.name) == 0) {
            return;
        }
        ui->textOutput->append(ship.display());
    }
    file.close();
    QMessageBox::information(this, "info", "Замечательно");
}

void MainWindow::StructToBinary() {
    QString fields = ui->textEdit->toPlainText();
    ui->textEdit->clear();
    QTextStream in(&fields);
    Ship ship;
    ReadShip(ship, in);
    QFile file(binaryFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "error" << file.errorString();
        return;
    }
    file.write(reinterpret_cast<const char*>(&ship), sizeof(Ship));
    file.close();
    QMessageBox::information(this, "info", "Структура успешно добавлена");
}

void MainWindow::BinaryToStruct() {
    qDebug() << sizeof(Ship);
    QFile file(binaryFile);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "error" << file.errorString();
        ui->textOutput->clear();
        QMessageBox::critical(this, "error", "Файл не найден");
        return;
    }
    ui->textOutput->clear();
    while (!file.atEnd()) {
        Ship ship;
        if (file.read(reinterpret_cast<char*>(&ship), sizeof(Ship)) == sizeof(Ship)) {
            ui->textOutput->append(ship.display());
        } else {
            break;
        }
    }
    file.close();
    QMessageBox::information(this, "info", "Великолепно");
}

void MainWindow::Cycling() {
    while (true) {
        int operation = Input();
        switch (operation) {
            case 0:
                Quit();
                break;
            case 1:
                ParagraphToFile();
                break;
            case 2:
                FileToParagraph();
                break;
            case 3:
                ArrayToFile();
                break;
            case 4:
                FileToArray();
                break;
            case 5:
                StructToFile();
                break;
            case 6:
                FileToStruct();
                break;
            case 7:
                StructToBinary();
                break;
            case 8:
                BinaryToStruct();
                break;
            default:
                break;
        }
    }
}

