#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Проверка последнего элемента
        if (a[n-1] != -1) {
            cout << "NO" << endl;
            continue;
        }

        // Проверка на наличие не--1 элементов
        bool has_non_minus_one = false;
        for (int num : a) {
            if (num != -1) {
                has_non_minus_one = true;
                break;
            }
        }

        if (!has_non_minus_one) {
            cout << "YES" << endl;
            continue;
        }

        // Подсчет последовательных -1 в начале
        int count_begin = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) {
                count_begin++;
            } else {
                break;
            }
        }

        // Проверка количества -1 в начале
        if (count_begin == 0 || count_begin == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}