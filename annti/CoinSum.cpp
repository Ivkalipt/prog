#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, t, s = 1LL, maxi = 0;
    vector<ll> x;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        x.push_back(t);
    }
    sort(x.begin(), x.end());
    
    for(ll i = 0; i < n; i++) {
        if(x[i] > s) {
            cout << s;
            return 0;
        }
        s += x[i];
    }
    cout << s;
    

    
}