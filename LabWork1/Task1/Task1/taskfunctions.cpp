#include "datebase.h"

DateBase dateBase;

Date* ReadFromFile(int& n, QLabel *fileNameLabel, bool knowFile) {
    Date* arr = nullptr;
    dateBase.Init(knowFile);
    if (dateBase.GetFileName() == "") {
        fileNameLabel->setText("File not chosen");
    }
    else {
        fileNameLabel->setText(dateBase.GetFileName());
    }
    Date nextDate;
    while ((nextDate = dateBase.ReadDate()).WeekNumber() >= 0) {
        n++;
        arr = (Date*)realloc(arr, n * sizeof(Date));
        arr[n - 1] = nextDate;
    }
    dateBase.Close();
    return arr;
}

DateBase* Dates() {
    return &dateBase;
}
