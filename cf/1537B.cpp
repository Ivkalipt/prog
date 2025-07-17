// #pragma GCC optimize ("O3, unroll-all-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

ll inf = 1e9 + 7;

void solve() {
    ll n, m, i, j;
    cin >> n >> m >> i >> j;
    pll f, s;
    ll midn = n / 2, midm = m / 2;
    if(i < midn && j < midm) f = {1, m}, s = {n, 1};
    else if(i < midn && j >= midm) f = {1, 1}, s = {n, m};
    else if(i >= midn && j < midm) f = {1, 1}, s = {n, m};
    else f = {1, m}, s = {n, 1};
    cout << f.F << ' ' << f.S << ' ' << s.F << ' ' << s.S << '\n'; 
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
