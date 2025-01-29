#include "date.h"

bool Date::IsLeap() const {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int Date::DaysInMonth() const {
    return months[month - 1] + (month == 2 && IsLeap());
}

int Date::DayNumber() const {
    int dayNumber = day;
    for (int i = 0; i < month - 1; i++) {
        dayNumber += months[i] + (IsLeap() && i == 1);
    }
    return dayNumber;
}

void Date::SwitchNextDay() {
    day++;
    if (day > DaysInMonth()) {
        month++;
        day = 1;
        if (month > 12) {
            year++;
            month = 1;
        }
    }
}

Date Date::NextDay() {
    Date nextDay(*this);
    nextDay.SwitchNextDay();
    return nextDay;
}

void Date::SwitchPreviousDay() {
    day--;
    if (day == 0) {
        month--;
        if (month < 1) {
            year--;
            month = 12;
        }
        day = months[month - 1];
    }
}

Date Date::PreviousDay() {
    Date previousDay(*this);
    previousDay.SwitchPreviousDay();
    return previousDay;
}

int Date::WeekNumber() {
    return (DayNumber() + 6) / 7;
}

int Date::DaysTillYourBirthday(Date birthdayDate) {
    birthdayDate.year = year;
    if (birthdayDate.DayNumber() >= DayNumber()) {
        return birthdayDate.DayNumber() - DayNumber();
    }
    birthdayDate.year++;
    return birthdayDate.DayNumber() - DayNumber() + (365 + (int)IsLeap());
}

int Date::Duration(Date date) {
    if (year == date.year) {
        return abs(DayNumber() - date.DayNumber());
    }
    int delta = 0;
    for (int i = std::min(year, date.year) + 1; i < std::max(year, date.year); i++) {
        delta += 365 + Date(0, 0, i).IsLeap();
    }
    if (year > date.year) {
        delta += DayNumber() + (365 + date.IsLeap()) - date.DayNumber();
    }
    else {
        delta += date.DayNumber() + (365 + IsLeap()) - DayNumber();
    }
    return delta;
}

void Date::Read(std::fstream &in) {
    std::string date;
    in >> date;
    day = (date[0] - '0') * 10 + (date[1] - '0');
    month = (date[3] - '0') * 10 + (date[4] - '0');
    year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
}

Date::Date(QString date) {
    day = (date[0].toLatin1() - '0') * 10 + (date[1].toLatin1() - '0');
    month = (date[3].toLatin1() - '0') * 10 + (date[4].toLatin1() - '0');
    year = (date[6].toLatin1() - '0') * 1000 + (date[7].toLatin1() - '0') * 100 + (date[8].toLatin1() - '0') * 10 + (date[9].toLatin1() - '0');
}

QString Date::StringView() {
    QString stringView = "";
    if (day < 10) {
        stringView += "0";
    }
    stringView  += QString::number(day) + ".";
    if (month < 10) {
        stringView += "0";
    }
    stringView  += QString::number(month) + ".";
    if (year < 1000) {
        stringView += "0";
    }
    if (year < 100) {
        stringView += "0";
    }
    if (year < 10) {
        stringView += "0";
    }
    stringView += QString::number(year);
    return stringView;
}

Date Today() {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    return Date(day, month, year);
}

bool Date::IsCorrect() {
    return month >= 1 && month <= 12 && day >= 1 && day <= months[month - 1];
}

bool IsDate(QString date) {
    std::string sDate = date.toStdString();
    for (int i = 0; i < (int)sDate.size(); i++) {
        if (sDate[i] >= '0' && sDate[i] <= '9') {
            sDate[i] = '0';
        }
    }
    if (sDate != "00.00.0000") {
        return false;
    }
    return Date(date).IsCorrect();
}
