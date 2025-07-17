#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define F first
#define S second

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;

const ll maxn = 1e5;

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vll a(n), diffs(n), pref(n);
    for (ll & c : a) cin >> c;
    for (ll i = 1; i < n; i++) {
        diffs[i] = (a[i] > a[i - 1] ? 1 : 0);
        pref[i] = pref[i - 1] + diffs[i];
    }
    while (m--) {
        ll l, r;
        cin >> l >> r;
        cout << pref[r - 1] - pref[l - 1] << '\n';
    }
    // for (ll c : diffs) cout << c << ' ';
    // cout << '\n';
}