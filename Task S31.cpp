#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main() {
    setlocale(0,"Russian");

    string digits[10] = {"ноль", "один", "два", "три", "четыре",
                         "пять", "шесть", "семь", "восемь", "девять"};

    int num;
    cout << "Введите цифру от 0 до 9: ";
    cin >> num;

    if (num >= 0 && num <= 9) {
        cout << "Название: " << digits[num] << endl;
    } else {
        cout << "Ошибка! Введите цифру от 0 до 9." << endl;
    }

    return 0;
}
