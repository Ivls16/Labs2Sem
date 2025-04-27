#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->lineEditKey->setValidator(new QIntValidator(this));
    ui->treeWidget->setColumnCount(2);
    QFont font = ui->treeWidget->font();
    font.setPointSize(16);
    font.setBold(true);
    ui->treeWidget->setFont(font);
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    tree = new SearchTree(this, ui->treeWidget);
    tree->addNode(10, "a");
    tree->addNode(5, "b");
    tree->addNode(15, "c");
    tree->addNode(7, "c");
    tree->addNode(6, "x");
    tree->addNode(8, "d");
    tree->addNode(9, "o");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_buttonAdd_clicked() {
    int key = ui->lineEditKey->text().toInt();
    std::string value = ui->lineEditValue->text().toStdString();
    if (value == "") {
        return;
    }
    tree->addNode(key, value);
    clearUi();
}

void MainWindow::on_buttonDelete_clicked() {
    int key = ui->lineEditKey->text().toInt();
    tree->deleteByKey(key);
    clearUi();
}

void MainWindow::clearUi() {
    ui->treeWidget->expandAll();
    ui->lineEditKey->clear();
    ui->lineEditValue->clear();
}


void MainWindow::on_buttonFind_clicked() {
    int key = ui->lineEditKey->text().toInt();
    tree->findByKey(key);
    clearUi();
}


void MainWindow::on_buttonPreorder_clicked() {
    tree->preorder();
}


void MainWindow::on_buttonPostorder_clicked() {
    tree->postorder();
}


void MainWindow::on_buttonInorder_clicked() {
    tree->inorder();
}


void MainWindow::on_buttonBalance_clicked() {
    tree->balance();
}

