#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <clocale>
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
    setlocale(LC_ALL, "Russian");

    vector<Item> all;
    all.push_back(Item("БАНАНЫ", 200));
    all.push_back(Item("ЛИМОНЫ", 120));
    all.push_back(Item("ИМБИРЬ", 300));
    all.push_back(Item("ЯБЛОКИ", 500));
    all.push_back(Item("ГРУШИ", 1000));
    all.push_back(Item("АБРИКОСЫ", 350));
    all.push_back(Item("ПОМИДОРЫ", 45));
    all.push_back(Item("УКРОП", 50));
    all.push_back(Item("ВИНО", 100));
    all.push_back(Item("ТОРТ", 650));

    cout << "=== СПИСОК ТОВАРОВ ===" << endl;
    for (int i = 0; i < all.size(); i++) {
        cout << i + 1 << ". " << all[i].name << " - " << all[i].price << " РУБ." << endl;
    }

    vector<Item> items;
    int count;
    cout << "\nСКОЛЬКО ТОВАРОВ ХОТИТЕ КУПИТЬ? ";
    if (!(cin >> count)) {
        cout << "ОШИБКА! НУЖНО ВВЕСТИ ЧИСЛО." << endl;
        return 1;
    }

    if (count < 1) {
        cout << "ОШИБКА: НУЖНО ХОТЯ БЫ 1 ТОВАР." << endl;
        return 1;
    }

    cout << "ВВЕДИТЕ НОМЕРА ТОВАРОВ ЧЕРЕЗ ПРОБЕЛ: ";
    for (int i = 0; i < count; i++) {
        int num;
        if (!(cin >> num)) {
            cout << "ОШИБКА! НУЖНО ВВЕСТИ ЧИСЛО." << endl;
            return 1;
        }
        if (num >= 1 && num <= all.size()) {
            items.push_back(all[num - 1]);
        } else {
            cout << "ТОВАР С НОМЕРОМ " << num << " НЕ СУЩЕСТВУЕТ. ПОПРОБУЙТЕ СНОВА." << endl;
            i--;
        }
    }

    cout << "\n=== ВЫБЕРИТЕ СПОСОБ ОПЛАТЫ ===" << endl;
    cout << "1 - БЕЗ БОНУСНОЙ КАРТЫ" << endl;
    cout << "2 - С БОНУСНОЙ КАРТОЙ" << endl;
    cout << "ВАШ ВЫБОР: ";

    int mode;
    if (!(cin >> mode)) {
        cout << "ОШИБКА! НУЖНО ВВЕСТИ ЧИСЛО." << endl;
        return 1;
    }

    if (mode == 1) {
        cout << "\n=== ПОКУПКА БЕЗ БОНУСНОЙ КАРТЫ ===" << endl;
        float totalSpent = 0;
        for (int i = 0; i < items.size(); i++) {
            totalSpent += items[i].price;
            cout << "КУПЛЕНО: " << items[i].name << " ЗА " << items[i].price << " РУБ." << endl;
        }
        cout << "ИТОГО ПОТРАЧЕНО ДЕНЕГ: " << totalSpent << " РУБ." << endl;
        cout << "БОНУСОВ НАЧИСЛЕНО: 0" << endl;
    }
    else if (mode == 2) {
        cout << "\n=== ПОКУПКА С БОНУСНОЙ КАРТОЙ ===" << endl;

        sort(items.begin(), items.end(), [](Item a, Item b) {
            return a.price < b.price;
        });

        float totalBonus = 0;
        float totalSpent = 0;

        for (int i = 0; i < items.size() - 1; i++) {
            totalBonus += items[i].bonus(3);
            totalSpent += items[i].price;
            cout << "КУПЛЕНО: " << items[i].name << " ЗА " << items[i].price
                 << " РУБ. (БОНУС +" << items[i].bonus(3) << ")" << endl;
        }

        Item lastItem = items.back();
        cout << "\nПОКУПАЕМ ПОСЛЕДНИЙ ТОВАР ЗА БОНУСЫ: " << lastItem.name
             << " ЗА " << lastItem.price << " РУБ." << endl;

        if (totalBonus >= lastItem.price) {
            totalBonus -= lastItem.price;
            cout << "ОПЛАЧЕНО БОНУСАМИ." << endl;
        } else {
            float doplata = lastItem.price - totalBonus;
            totalSpent += doplata;
            totalBonus = 0;
            cout << "БОНУСОВ НЕ ХВАТИЛО. ДОПЛАТА: " << doplata << " РУБ." << endl;
        }

        cout << "ИТОГО ПОТРАЧЕНО ДЕНЕГ: " << totalSpent << " РУБ." << endl;
        cout << "ОСТАТОК БОНУСОВ: " << totalBonus << endl;
    }
    else {
        cout << "НЕВЕРНЫЙ ВЫБОР. ПРОГРАММА ЗАВЕРШЕНА." << endl;
        return 1;
    }

    return 0;
}
