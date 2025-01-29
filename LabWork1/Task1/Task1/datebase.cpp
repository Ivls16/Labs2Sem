#include "datebase.h"

void DateBase::Init(bool knowFile) {
    if (!knowFile) {
        fileName = QFileDialog::getOpenFileName(0, "Choose file", "", "*.txt");
    }
    chosen = fileName != "";
    if (!chosen) {
        return;
    }
    dateBase.open(fileName.toStdString(), std::ios::in | std::ios::out);
}

void DateBase::Close() {
    dateBase.close();
}

bool DateBase::ChosenFile() {
    return chosen;
}

QString DateBase::GetFileName() {
    return fileName;
}

Date DateBase::ReadDate() {
    std::string rawDate;
    dateBase >> rawDate;
    if (rawDate == "") {
        return Date(-100, -100, -100);
    }
    else {
        return Date(QString::fromStdString(rawDate));
    }
}

void DateBase::Write(int position, std::string text) {
    if (position != -1) {
        dateBase.open(fileName.toStdString(), std::ios::in | std::ios::out);
        dateBase.seekp(position);
    }
    else {
        dateBase.open(fileName.toStdString(), std::ios::app);
    }
    dateBase << text << '\n';
    dateBase.close();
}
