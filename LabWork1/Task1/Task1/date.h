#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <QString>

class Date {
private:
    int day, month, year;

    constexpr const static int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int DaysInMonth() const;
    int DayNumber() const;
public:
    Date(): day(0), month(0), year(0) {}
    Date(int day, int month, int year): day(day), month(month), year(year) {}
    Date(QString);

    bool IsLeap() const;

    QString StringView();

    void Read(std::fstream &in);

    void SwitchNextDay();
    Date NextDay();
    void SwitchPreviousDay();
    Date PreviousDay();

    int WeekNumber();

    int DaysTillYourBirthday(Date);

    int Duration(Date);

    bool IsCorrect();
};

Date Today();
bool IsDate(QString);
