#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for(int i = n-1; i >= 0; i--) {
        for(int j = n-1; j >= 0; j--) {
            cin >> a[j][i];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}