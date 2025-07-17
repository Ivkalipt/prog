#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<long long>;

const ll MAX = 1e5, inf = 1e18;
ll tin[MAX], tout[MAX], up[MAX][30], w[MAX], mn[MAX][30];
vll g[MAX];
ll t = 0, l = 30;

void dfs(ll v, ll prev) {
    tin[v] = t++;
    for (ll i = 1; i <= l; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        mn[v][i] = min(mn[v][i - 1], mn[up[v][i - 1]][i - 1]);
    }
    for (ll u : g[v]) {
        if (u != prev) {
            dfs(u, v);
        }
    }
    tout[v] = t++;
}

bool check(ll u, ll v) {
    return tin[u] <= tin[v] && tin[v] < tout[u];
}

ll lca(ll u, ll v) {
    ll ans = inf;
    if (check(u, v)) swap(u, v);
    for (ll i = l - 1; i > -1; i--) {
        if (!check(up[u][i], v)) {
            u = up[u][i];
            ans = min(ans, mn[u][i]);
        }
    }

    return min(ans, mn[u][0]);
}

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        g[x].push_back(i);
        up[i][0] = x;
        mn[i][0] = y;
    }
    ll m;
    cin >> m;
    dfs(0, 0);
    while (m--) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        cout << min(lca(u, v), lca(v, u)) << '\n';
    }
    return 0;
}
