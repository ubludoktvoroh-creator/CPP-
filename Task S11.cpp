#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    for (int i = 0; i <= 100; i++) {
        if (i % 3 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
