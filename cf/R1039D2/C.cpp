#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;


void solve() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (ll & x : a) cin >> x;
    ll left = 1, right = n;
    ll best_v = 1;
    // pll best = {1};
    ll best_lx = 1, best_rx = 1;

    while (left <= right) {
        ll m = (left + right) >> 1;
        vll prefix(n + 1, 0);
        for (ll i = 1; i <= n; ++i)
            prefix[i] = prefix[i - 1] + (a[i - 1] >= m ? 1 : -1);

        bool f = 0;
        ll min_prefix = 0;
        ll best_l = 0;

        for (ll i = k; i <= n; ++i) {
            if (prefix[i] - min_prefix > 0) {
                f = true;
                best_l = i - k;
                break;
            }
            if (i - k + 1 > 0)
                min_prefix = min(min_prefix, prefix[i - k + 1]);
        }

        if (f) {
            best_v = m;
            best_lx = best_l + 1;
            best_rx = best_l + k;
            left = m + 1;
        }
        else
            right = m - 1;
    }

    cout << best_v << ' ' << best_lx << ' ' << best_rx << '\n';
}

signed main() { ll t; cin >> t; while (t--) solve(); }