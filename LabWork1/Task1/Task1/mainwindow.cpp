#include "mainwindow.h"
#include "taskfunctions.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    warningBox = ui->warning;
    warningBox->setStyleSheet("color: red");
    table = ui->tableWidget;
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({"Date", "Next Day", "Next Diff"});
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetWarning(bool good, QString message) {
    if (good) {
        warningBox->setText("");
    }
    else {
        warningBox->setText(message);
    }
}

void MainWindow::on_resetTable_clicked(bool knowFile) {
    int n = 0;
    Date* arr = ReadFromFile(n, ui->label_2, knowFile);
    table->setRowCount(n);
    for (int i = 0; i < n; i++) {
        table->setItem(i, 0, new QTableWidgetItem(arr[i].StringView()));
        table->setItem(i, 1, new QTableWidgetItem(arr[i].NextDay().StringView()));
        table->item(i, 1)->setFlags(table->item(i, 1)->flags() &= ~Qt::ItemIsEditable);
        if (i + 1 != n) {
            table->setItem(i, 2, new QTableWidgetItem(QString::number(arr[i].Duration(arr[i + 1]))));
            table->item(i, 2)->setFlags(table->item(i, 2)->flags() &= ~Qt::ItemIsEditable);
        }
    }
    delete[] arr;
}

void OnItemChanged(QTableWidgetItem *item) {
    int i = item->row();
    Date date(item->text());
    item->tableWidget()->setItem(i, 1, new QTableWidgetItem(date.NextDay().StringView()));
    item->tableWidget()->item(i, 1)->setFlags(item->tableWidget()->item(i, 1)->flags() &= ~Qt::ItemIsEditable);
    if (i + 1 != item->tableWidget()->rowCount() && item->tableWidget()->item(i + 1, 0)) {
        Date nextDate(item->tableWidget()->item(i + 1, 0)->text());
        item->tableWidget()->setItem(i, 2, new QTableWidgetItem(QString::number(date.Duration(nextDate))));
        item->tableWidget()->item(i, 2)->setFlags(item->tableWidget()->item(i, 2)->flags() &= ~Qt::ItemIsEditable);
    }
    if (i > 0) {
        Date date(item->text());
        Date nextDate(item->tableWidget()->item(i - 1, 0)->text());
        item->tableWidget()->setItem(i - 1, 2, new QTableWidgetItem(QString::number(date.Duration(nextDate))));
        item->tableWidget()->item(i - 1, 2)->setFlags(item->tableWidget()->item(i - 1, 2)->flags() &= ~Qt::ItemIsEditable);
    }
}

void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item) {
    if (item->column() != 0) {
        return;
    }
    if (!IsDate(item->text())) {
        item->setText("01.01.0001");
        SetWarning(false, "Incorrect date");
    }
    else {
        SetWarning(true, "Incorrect date");
    }
    Dates()->Write(11 * item->row(), item->text().toStdString());
    OnItemChanged(item);
}

bool correctDate;
Date currentDate;

void MainWindow::on_nextDay_clicked() {
    if (correctDate) {
        ui->label_3->setText(currentDate.NextDay().StringView());
    }
}

void MainWindow::on_previousDay_clicked() {
    if (correctDate) {
        ui->label_4->setText(currentDate.PreviousDay().StringView());
    }
}

void MainWindow::on_daysTillYourBirthday_clicked() {
    if (correctDate) {
        ui->label_5->setText(QString::number(Today().DaysTillYourBirthday(currentDate)));
    }
}

void MainWindow::on_duration_clicked() {
    if (correctDate) {
        ui->label_6->setText(QString::number(currentDate.Duration(Today())));
    }
}

void MainWindow::on_isLeap_clicked() {
    if (correctDate) {
        ui->label_7->setText(QString::number(currentDate.IsLeap()));
    }
}

void MainWindow::on_weekNumber_clicked() {
    if (correctDate) {
        ui->label_8->setText(QString::number(currentDate.WeekNumber()));
    }
}

void MainWindow::on_date_editingFinished() {
    SetWarning(IsDate(ui->date->text()), "Incorrect date");
    correctDate = IsDate(ui->date->text());
    ui->label_3->setText("undefined");
    ui->label_4->setText("undefined");
    ui->label_5->setText("undefined");
    ui->label_6->setText("undefined");
    ui->label_7->setText("undefined");
    ui->label_8->setText("undefined");
    if (correctDate) {
        currentDate = Date(ui->date->text());
    }
}

void MainWindow::on_date_textEdited() {
    SetWarning(false, "");
}

void MainWindow::on_addDate_clicked() {
    SetWarning(Dates()->ChosenFile(), "File not chosen");
    if (Dates()->ChosenFile()) {
        Dates()->Write(-1, "01.01.0001");
    }
    on_resetTable_clicked(true);
}

