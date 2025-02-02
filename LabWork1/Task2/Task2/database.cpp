#include "database.h"

Database::Database() {};

Database::Database(MainWindow* parent, bool type, QLabel* header, QString baseName,
                   QTableWidget* table, QStringList columnNames,
                   QPushButton* openButton, QPushButton* saveButton,
                   QPushButton* addButton, QPushButton* deleteButton):
    parent(parent), type(type),
    fileSetted(false), baseName(baseName), header(header), table(table),
    openButton(openButton), saveButton(saveButton), addButton(addButton), deleteButton(deleteButton) {
    table->setColumnCount(4);
    for (int i = 0; i < 4; i++) {
        table->setHorizontalHeaderLabels(columnNames);
    }
    connect(openButton, &QPushButton::clicked, this, &Database::OpenFile);
    connect(addButton, &QPushButton::clicked, this, &Database::AddLine);
    connect(deleteButton, &QPushButton::clicked, this, &Database::DeleteSelected);
    connect(saveButton, &QPushButton::clicked, this, &Database::SaveFile);
    table->setSortingEnabled(true);
    connect(table, &QTableWidget::cellChanged, this, &Database::ResetArray);
    connect(table, &QTableWidget::cellChanged, this, &Database::UpdateComboBox);
}

void Database::OpenFile() {
    QFile newFile = QFileDialog::getOpenFileName(0, "Выберите файл", "", "*.txt");
    if (newFile.open(QFile::ReadOnly)) {
        QTextStream in(&newFile);
        table->setRowCount(0);
        int n = 0;
        while (!in.atEnd()) {
            QString id, name, tin, tout, mass;
            in >> id >> name >> tin >> tout >> mass;
            if (id == "") {
                break;
            }
            ++n;
            table->insertRow(n - 1);
            {
                QTableWidgetItem *idw = new QTableWidgetItem(id.toInt());
                idw->setData(Qt::EditRole, id.toInt());
                table->setItem(n - 1, 0, idw);
            }
            table->setItem(n - 1, 1, new QTableWidgetItem(name));
            table->setItem(n - 1, 2, new QTableWidgetItem(TimeIntervalString(tin, tout)));
            table->setItem(n - 1, 3, new QTableWidgetItem(mass));
            {
                QTableWidgetItem *idw = new QTableWidgetItem(mass.toInt());
                idw->setData(Qt::EditRole, mass.toInt());
                table->setItem(n - 1, 3, idw);
            }
        }
        fileName = newFile.fileName();
        fileSetted = true;
    }
    else {
        table->setRowCount(0);
        fileName = "Файл не выбран";
        fileSetted = false;
    }
    header->setText(baseName + "(" + fileName + ")");
}

void Database::AddLine() {
    if (!fileSetted) {
        QMessageBox::warning(nullptr, tr("Warning"), tr("Файл не выбран"), QMessageBox::Cancel);
        return;
    }
    int n;
    table->insertRow(n = table->rowCount());
    {
        QTableWidgetItem *idw = new QTableWidgetItem(0);
        idw->setData(Qt::EditRole, 0);
        table->setItem(n, 0, idw);
    }
    table->setItem(n, 1, new QTableWidgetItem("untitled"));
    table->setItem(n, 2, new QTableWidgetItem(TimeIntervalString(0, 0)));
    {
        QTableWidgetItem *idw = new QTableWidgetItem(0);
        idw->setData(Qt::EditRole, 0);
        table->setItem(n, 3, idw);
    }
}

void Database::DeleteSelected() {
    if (!fileSetted) {
        QMessageBox::warning(nullptr, tr("Warning"), tr("Файл не выбран"), QMessageBox::Cancel);
        return;
    }
    int mn = 2e9, mx = -2e9;
    for (QTableWidgetItem* selected : table->selectedItems()) {
        mn = std::min(mn, selected->row());
        mx = std::max(mx, selected->row());
    }
    for (int i = 0; i < mx - mn + 1; i++) {
        table->removeRow(mn);
    }
}

QString TimeToMins(QString tm) {
    QString result = 0;
    int hour1 = (QString(tm[0]) + QString(tm[1])).toInt();
    int min1 = (QString(tm[3]) + QString(tm[4])).toInt();
    int hour2 = (QString(tm[6]) + QString(tm[7])).toInt();
    int min2 = (QString(tm[9]) + QString(tm[10])).toInt();
    return QString::number(hour1 * 60 + min1) + " " + QString::number(hour2 * 60 + min2);
}

std::chrono::minutes ToTime(QString tm, int offset) {
    QString result = 0;
    int hour1 = (QString(tm[0 + offset]) + QString(tm[1 + offset])).toInt();
    int min1 = (QString(tm[3 + offset]) + QString(tm[4 + offset])).toInt();
    return std::chrono::minutes(60 * hour1 + min1);
}

void Database::SaveFile() {
    if (!fileSetted) {
        QMessageBox::warning(nullptr, tr("Warning"), tr("Файл не выбран"), QMessageBox::Cancel);
        return;
    }
    QSaveFile file(QFileDialog::getSaveFileName(0, "Выберите файл для сохранения", "", "*.txt"));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text) || file.fileName() == "") {
            QMessageBox::warning(nullptr, tr("Warning"), tr("Файл не выбран или защищен от записи"), QMessageBox::Cancel);
            return;
        }
    QTextStream out(&file);
    for (int i = 0; i < table->rowCount(); i++) {
        out << table->item(i, 0)->text() << " " << table->item(i, 1)->text() << " ";
        out << TimeToMins(table->item(i, 2)->text()) << " ";
        out << table->item(i, 3)->text() << "\n";
    }
    file.commit();
}

void Database::ResetArray() {
    if (!type) {
        std::vector<Courier> *arr = parent->GetCourierArray();
        arr->resize(table->rowCount());
    }
    else {
        std::vector<Order> *arr = parent->GetOrderArray();
        arr->resize(table->rowCount());
    }
    for (int i = 0; i < table->rowCount(); i++) {
        if (!table->item(i, 0) || !table->item(i, 1) || !table->item(i, 2) || !table->item(i, 3)) {
            continue;
        }
        if (!type) {
            std::vector<Courier> *arr = parent->GetCourierArray();
            (*arr)[i].Setup(Courier(table->item(i, 0)->text().toInt(), table->item(i, 1)->text(), ToTime(table->item(i, 2)->text(), 0), ToTime(table->item(i, 2)->text(), 6), table->item(i, 3)->text().toInt()));
        }
        else {
            std::vector<Order> *arr = parent->GetOrderArray();
            (*arr)[i].Setup(Order(table->item(i, 0)->text().toInt(), table->item(i, 1)->text(), ToTime(table->item(i, 2)->text(), 0), ToTime(table->item(i, 2)->text(), 6), table->item(i, 3)->text().toInt()));
        }
    }
}

void Database::UpdateComboBox() {
    if (type) {
        return;
    }
    this->parent->ComboBox()->clear();
    for (int i = 0; i < table->rowCount(); i++) {
        this->parent->ComboBox()->addItem(table->item(i, 0)->text());
    }
}




