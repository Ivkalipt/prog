#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, t, s = 0, maxs=-1e9;
    vector<ll> x;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        x.push_back(t);
    }
    for(ll i = 0; i < n; i++) {
        s += x[i];
        maxs = max(maxs, s);
        s = max((ll)0, s);
    }
    cout << maxs << "\n";
}