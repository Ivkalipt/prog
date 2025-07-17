#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e9, num = 1e5 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll cntr = 0;
    cout << num << ' ' << num << '\n';
    for(ll i = 1; i < n - 1; i++) {
        cntr++;
        cout << i << ' ' << i + 1 << ' ' << 1 << '\n';
    }
    cout << n - 1 << ' ' << n << ' ' << num - n + 2 << '\n';
    cntr++;

    for(ll i = 1; i < n; i++) {
        for(ll j = i + 2; j <= n; j++) {
            cntr++;
            if(cntr > m) return;
            cout << i << ' ' << j << ' ' << inf << '\n';
        }
    }

}

int main() {
    solve();
}

