#include <iostream>
#include <string>
#include <clocale>
using namespace std;

string get_day_of_week(int d) {
    int day   = d / 10000;
    int month = (d / 100) % 100;
    int year  = d % 100;
    int full_year = (year < 70) ? 2000 + year : 1900 + year;

    int total_days = 0;

    for (int y = 1970; y < full_year; y += 4) {
        total_days += 366;
    }
    int leap_years = (full_year - 1970 + 3) / 4;          
    int normal_years = (full_year - 1970) - leap_years;   
    total_days = leap_years * 366 + normal_years * 365;

    int days_in_months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (int m = 0; m < month - 1; m++)
        total_days += days_in_months[m];

    if (month > 2 && full_year % 4 == 0)
        total_days++;

    total_days += day - 1;

    string days[] = {"четверг","пятница","суббота","воскресенье","понедельник","вторник","среда"};
    return days[total_days % 7];
}

int main() {
    setlocale(0, "Russian");
    int d;
    cout << "Введите дату ДДММГГ: ";
    cin >> d;

    int day = d / 10000, month = (d / 100) % 100, year = d % 100;
    int full_year = (year < 70) ? 2000 + year : 1900 + year;

    cout << day << "." << month << "." << full_year << " " << get_day_of_week(d) << endl;
}
