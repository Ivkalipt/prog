#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll maxn = 1e5;

ll dp[maxn], dp1[maxn], sz[maxn], n;
vector<pll> g[maxn];

void dfs(ll v, ll prev) {
    sz[v] = 1;
    for(pll u : g[v]) {
        if(u.S != prev) {
            dfs(u.S, v);
            sz[v] += sz[u.S];
            dp[v] += dp[u.S] + sz[u.S] * u.F;
        }
    }
}

void dfs1(ll v, ll prev) {
    for(pll u : g[v]) {
        if(u.S != prev) {
            dp1[u.S] += dp1[v] + u.F * (n - 2 * sz[u.S]);
            dfs1(u.S, v);
        }
    }
}

int main() {
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].push_back({w, u});
        g[u].push_back({w, v});
    }
    dfs(0, 0);
    dp1[0] = dp[0];
    dfs1(0, 0);
    for(ll i = 0; i < n; i++) {
        cout << dp1[i] << ' ';
    }

}
