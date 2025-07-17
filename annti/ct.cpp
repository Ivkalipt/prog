// *
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, m, temp, i, j;
    vector<ll> x;
    vector<ll> t;
    for(ll i = 0; i < n; i++) {
        cin >> temp;
        x.push_back(temp);
    }
    for(ll i = 0; i < m; i++) {
        cin >> temp;
        t.push_back(temp);
    }
    sort(x.rbegin(), x.rend());
    sort(t.rbegin(), t.rend());
    while(i < n && j < m) {
        if(x[i] <= t[j]) {
            cout << x[i] << "\n";
            i++; j++;
        } else {
            i++;
            if(i == n-1) {
                for(ll l = 0; l < m-j; l++) {
                    cout << -1;
                }
            }
        }
        
    }
}