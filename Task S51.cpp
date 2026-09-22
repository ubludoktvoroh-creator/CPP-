#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void reverse(string s) {
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string word;
    cout << "¬ведите слово: ";
    getline(cin, word);

    reverse(word);

    return 0;
}
