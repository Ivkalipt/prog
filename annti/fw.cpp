#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, x, t, s=0, l=0, r;
    cin >> n >> x;
    vector<ll> p;
    r = n-1;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        p.push_back(t);
    }
    sort(p.begin(), p.end());
    while(l <= r) {
        if(p[l] + p[r] <= x) {
            s++; l++; r--;
        }
        else
        {
            s++; r--;
        }
    }
    cout << s << "\n";
}