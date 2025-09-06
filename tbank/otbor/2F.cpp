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
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

void dfs(ll v, ll prev, const vvll & g, vll & sub) {
    vll childs;
    for (ll u : g[v]) {
        if (u == prev) continue;
        dfs(u, v, g, sub);
        childs.pb(sub[u]);
    }
    
    if (childs.empty()) {
        sub[v] = 1;
    } else if (childs.size() == 1) {
        sub[v] = childs[0] + 1;
    } else {
        ll mn = INF;
        for (ll x : childs) {
            if (x < mn) mn = x;
        }
        sub[v] = mn * 2 + 1;
    }
}

void solve() {
    ll n;
    cin >> n;
    vvll g(n);
    rep(i, 0, n-1) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vll sub(n, 0);
    dfs(0, -1, g, sub);
    cout << sub[0] << '\n';
}

int main() { 
    fastio;
    ll t; 
    cin >> t; 
    while (t--) solve(); 
}
