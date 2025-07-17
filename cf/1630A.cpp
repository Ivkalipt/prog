#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<long long>;

ll inf = 1e16;

ll S(ll k, ll n) {
    return k ^ (n - 1);
}

void solve() {
    ll n, k;
    cin >> n >> k;
    if(k < n - 1) {
        cout << k << ' ' << n - 1 << '\n';
        for(ll i = n - 2; i >= n / 2; i--) {
            if(n - 1 - i == k) {cout << 0 << ' ' << i << '\n'; continue;}
            if(i == k) {cout << 0 << ' ' << n - i - 1 << '\n'; continue;}
            cout << n - 1 - i << ' ' << i << '\n';
            
        }
    }
    else {
        bool f = 1;
        if(n < 8) {cout << -1 << '\n'; return;}
        cout << n - 1 << ' ' << n - 2 << '\n';
        for(ll i = n - 3; i >= n / 2; i--) {
            if((i & 1) && f) {
                cout << 1 << ' ' << i << '\n';
                cout << 0 << ' ' << n - 1 - i << '\n';
                f = 0;
            }
            else {
                cout << i << ' ' << n - 1 - i << '\n';
            }
        }
    }
}
int main() {
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
