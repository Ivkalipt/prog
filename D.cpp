#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

vll d;

void divide(ll level, ll l, ll r, vll & a) {
    ll mx = max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
    d[mx] = level;
    // cout << l << ' ' << r << ' ' << mx << '\n';
    if (l < mx) divide(level + 1, l, mx - 1, a);
    if (mx < r) divide(level + 1, mx + 1, r, a);
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll & x : a) cin >> x;
    d.resize(n, -1);
    divide(0, 0, n - 1, a);
    for (ll x : d) cout << x << ' ';
    cout << '\n';
}

signed main() {
    ll t; cin >> t; while (t--) solve();
}