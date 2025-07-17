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

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    sort(all(a));
    ll M = a[0];
    for(ll i = 1; i < n; i++) {
        M = M + a[i] - 1;
    }
    cout << M << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
