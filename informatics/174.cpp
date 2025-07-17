#include <iostream>

using namespace std;

int main() {
    int n, s=0, w;
    cin >> n;
    for(int i = 0; i < n*n; i++) {
        cin >> w;
        if (w == 1) {
            s++;
        }
    }
    cout << s/2;
}