#include <iostream>
#include <windows.h>
using namespace std;

class CreditCard {
public:
    int Number;
    float Balance;

    CreditCard(int num, float bal) {
        Number = num;
        Balance = bal;
    }

    void Put(float V) {
        Balance += V;
        cout << "Пополнение: +" << V << " руб. Баланс: " << Balance << " руб." << endl;
    }

    void Take(float V) {
        if (V > Balance) {
            cout << "Недостаточно средств! Баланс: " << Balance << " руб." << endl;
        } else {
            Balance -= V;
            cout << "Снятие: -" << V << " руб. Баланс: " << Balance << " руб." << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    CreditCard card(1234, 0);
    CreditCard* ptr = &card;

    int choice;
    float amount;

    cout << "Номер карты: **** **** **** " << ptr->Number << endl;
    cout << "Баланс: " << ptr->Balance << " руб." << endl;

    while (true) {
        cout << "\n--- Меню ---" << endl;
        cout << "1 - Пополнить" << endl;
        cout << "2 - Снять" << endl;
        cout << "3 - Посмотреть баланс" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выбор: ";
        cin >> choice;

        if (choice == 0) {
            cout << "До свидания!" << endl;
            break;
        }

        if (choice == 1) {
            cout << "Введите сумму для пополнения: ";
            cin >> amount;
            ptr->Put(amount);
        }
        else if (choice == 2) {
            cout << "Введите сумму для снятия: ";
            cin >> amount;
            ptr->Take(amount);
        }
        else if (choice == 3) {
            cout << "Номер карты: **** **** **** " << ptr->Number << endl;
            cout << "Текущий баланс: " << ptr->Balance << " руб." << endl;
        }
        else {
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    }

    return 0;
}
