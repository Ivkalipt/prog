#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    map<ll, ll> p {
        {0, 3},
        {1, 1},
        {2, 2},
        {3, 1},
        {5, 1},
    };
    for(ll i = 0; i < n; i++) {
        if(p.count(a[i])) {
            p[a[i]]--;
            if(p[a[i]] == 0) p.erase(a[i]);
            if(p.empty()) {
                cout << i + 1 << '\n';
                return;
            }
        }
    }
    cout << 0 << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
