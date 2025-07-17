#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<long long>;

ll p[31];

bool isPow2(ll x) {
    return (x & (x - 1)) == 0;
}

bool isTr(ll a, ll b, ll c) {
    return (a < b + c) && (b < a + c) && (c < a + b);
}

void solve() {
    ll x;
    cin >> x;
    if(isPow2(x) || isPow2(x + 1)) {
        cout << -1 << '\n';
        return;
    }
    for(ll i = 0; i <= 30; i++) {
        ll y = (1 << i) + 1;
        if(isTr(x, y, x ^ y)) {
            cout << y << '\n';
            return;
        }
    }
    
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
