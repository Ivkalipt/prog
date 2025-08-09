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

constexpr ll INF = 4e18;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll & x : a) cin >> x;
    for (ll & x : b) cin >> x;

    vector<pll> seg;
    seg.reserve(n);
    ll baseSum = 0;
    for (ll i = 0; i < n; ++i) {
        ll l = min(a[i], b[i]);
        ll h = max(a[i], b[i]);
        seg.emplace_back(l, h);
        baseSum += h - l;
    }

    sort(all(seg), [](pll & x, pll & y) { return x.F < y.F; });

    ll max_hi = seg[0].S;
    ll best_gap = INF;
    bool has_over_lap = 0;

    for (int i = 1; i < n; ++i) {
        ll li = seg[i].F, hi = seg[i].S;
        if (max_hi >= li) {
            has_over_lap = 1;
            break;
        }
        best_gap = min(best_gap, li - max_hi);
        max_hi = max(max_hi, hi);
    }

    ll ans = baseSum;
    if (!has_over_lap) ans += 2 * best_gap;

    cout << ans << '\n';
}

int main() {
    fastio;

    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}
