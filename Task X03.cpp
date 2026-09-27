#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

class Item {
public:
    string name;
    float price;

    Item(string n, float p) {
        name = n;
        price = p;
    }

    float bonus(int n) {
        return price * n / 100.0;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<Item> all;
    all.push_back(Item("яблоки", 200));
    all.push_back(Item("молоко", 120));
    all.push_back(Item("конфеты", 300));
    all.push_back(Item("масло", 500));
    all.push_back(Item("орехи", 1000));
    all.push_back(Item("колбаса", 350));
    all.push_back(Item("горчица", 45));
    all.push_back(Item("хлеб", 50));
    all.push_back(Item("чай", 100));
    all.push_back(Item("торт", 650));

    cout << "=== Список товаров ===" << endl;
    for (int i = 0; i < all.size(); i++) {
        cout << i + 1 << ". " << all[i].name << " - " << all[i].price << " руб." << endl;
    }

    vector<Item> items;
    int count;
    cout << "\nСколько товаров хотите купить? ";
    if (!(cin >> count)) {
        cout << "Ошибка! Нужно ввести число." << endl;
        return 1;
    }

    if (count < 1) {
        cout << "Ошибка: нужно хотя бы 1 товар." << endl;
        return 1;
    }

    cout << "Введите номера товаров через пробел: ";
    for (int i = 0; i < count; i++) {
        int num;
        if (!(cin >> num)) {
            cout << "Ошибка! Нужно ввести число." << endl;
            return 1;
        }
        if (num >= 1 && num <= all.size()) {
            items.push_back(all[num - 1]);
        } else {
            cout << "Товар с номером " << num << " не существует. Попробуйте снова." << endl;
            i--;
        }
    }

    // === ВЫБОР: С БОНУСНОЙ КАРТОЙ ИЛИ БЕЗ ===
    cout << "\n=== Выберите способ оплаты ===" << endl;
    cout << "1 - Без бонусной карты" << endl;
    cout << "2 - С бонусной картой" << endl;
    cout << "Ваш выбор: ";

    int mode;
    if (!(cin >> mode)) {
        cout << "Ошибка! Нужно ввести число." << endl;
        return 1;
    }

    if (mode == 1) {
        // === БЕЗ БОНУСНОЙ КАРТЫ ===
        cout << "\n=== ПОКУПКА БЕЗ БОНУСНОЙ КАРТЫ ===" << endl;
        float totalSpent = 0;
        for (int i = 0; i < items.size(); i++) {
            totalSpent += items[i].price;
            cout << "Куплено: " << items[i].name << " за " << items[i].price << " руб." << endl;
        }
        cout << "Итого потрачено денег: " << totalSpent << " руб." << endl;
        cout << "Бонусов начислено: 0" << endl;
    }
    else if (mode == 2) {
        // === С БОНУСНОЙ КАРТОЙ ===
        cout << "\n=== ПОКУПКА С БОНУСНОЙ КАРТОЙ ===" << endl;

        sort(items.begin(), items.end(), [](Item a, Item b) {
            return a.price < b.price;
        });

        float totalBonus = 0;
        float totalSpent = 0;

        for (int i = 0; i < items.size() - 1; i++) {
            totalBonus += items[i].bonus(3);
            totalSpent += items[i].price;
            cout << "Куплено: " << items[i].name << " за " << items[i].price
                 << " руб. (бонус +" << items[i].bonus(3) << ")" << endl;
        }

        Item lastItem = items.back();
        cout << "\nПокупаем последний товар за бонусы: " << lastItem.name
             << " за " << lastItem.price << " руб." << endl;

        if (totalBonus >= lastItem.price) {
            totalBonus -= lastItem.price;
            cout << "Оплачено бонусами." << endl;
        } else {
            float doplata = lastItem.price - totalBonus;
            totalSpent += doplata;
            totalBonus = 0;
            cout << "Бонусов не хватило. Доплата: " << doplata << " руб." << endl;
        }

        cout << "Итого потрачено денег: " << totalSpent << " руб." << endl;
        cout << "Остаток бонусов: " << totalBonus << endl;
    }
    else {
        cout << "Неверный выбор. Программа завершена." << endl;
        return 1;
    }

    return 0;
}
