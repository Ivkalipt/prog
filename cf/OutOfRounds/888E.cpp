#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

void solve() {
    vll sums;
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for (ll & x : a) cin >> x;
    ll l = n / 2;
    for (ll mask = 0; mask < (1 << l); mask++) {
        ll s = 0;
        for (ll i = 0; i < l; i++) {
            if (mask >> i & 1) s += a[i];
        }
        sums.push_back(s % m);
    }
    sort(all(sums));
    sums.erase(unique(all(sums)), sums.end());
    ll r = n - l;
    ll ans = 0;
    for (ll mask = 0; mask < (1 << r); mask++) {
        ll s = 0;
        for (ll i = 0; i < r; i++) {
            if (mask >> i & 1) s += a[l + i];
        }
        s %= m;
        ll x = m - s;
        ll lx = 0, rx = sz(sums);
        while (rx - lx > 1) {
            ll mid = (lx + rx) >> 1;
            if (x <= sums[mid]) rx = mid;
            else lx = mid;
        }
        ans = max({ans, (s + sums[lx]) % m, (s + sums.back()) % m});
    }
    cout << ans << '\n';
}

int main() {
    solve();
}
