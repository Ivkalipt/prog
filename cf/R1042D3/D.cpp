#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 2e5;

void solve() {
    ll n;
    cin >> n;
    vvll g(n);
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vll cnt(n);
    for (vll & v : g)
        if (v.size() == 1)
            for (ll & u : v)
                cnt[u]++;
    ll to = 0;
    for (ll i = 0; i < n; ++i)
        if (cnt[i] > cnt[to]) to = i;
    ll ans = 0;
    for (vll & v : g)
        if (v.size() == 1)
            ans++;
    cout << ans - cnt[to] - (g[to].size() == 1) << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}