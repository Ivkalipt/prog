#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ll t, n, k;
    cin >> t;
    for(ll _ = 0; _ < t; _++) {
        cin >> n >> k;
        if (n == k) {
            for(ll i = 0; i < n; i++) {
                cout << 1 << " ";
            }
        }
        else if (k == 1)
        {
            cout << n+1 << " ";
            for(ll i = 1; i <= n; i++)
            cout << i << " ";
        }
        else
        {
            cout << "-1";
        }
        cout << "\n";
    }
}