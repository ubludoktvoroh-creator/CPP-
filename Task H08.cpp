#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

string get_day_of_week(int d) {
    int day = d / 10000;
    int month = (d / 100) % 100;
    int year = d % 100;

    int full_year;
    if (year < 70) {
        full_year = 2000 + year;
    } else {
        full_year = 1900 + year;
    }

    int years_passed = full_year - 1970;
    int total_days = years_passed * 365;

    int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int m = 1; m < month; m++) {
        total_days += days_in_months[m - 1];
    }

    total_days += (day - 1);

    string days[] = {"четверг", "пятница", "суббота", "воскресенье", "понедельник", "вторник", "среда"};
    return days[total_days % 7];
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int d;
    cout << "Введите дату в формате ДДММГГ: ";
    cin >> d;

    int day = d / 10000;
    int month = (d / 100) % 100;
    int year = d % 100;

    int full_year;
    if (year < 70) {
        full_year = 2000 + year;
    } else {
        full_year = 1900 + year;
    }

    cout << day << "." << month << "." << full_year << " " << get_day_of_week(d) << endl;

    return 0;
}
