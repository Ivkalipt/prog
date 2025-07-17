#pragma GCC optimize ("O3,unroll-loops")
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

const ll inf = 1e5 + 10;
ll tin[inf], tout[inf], up[inf][20], w[inf], pref[inf];
vll g[inf];
ll t = 0, l;

void dfs(ll v, ll prev) {
    tin[v] = t++;
    up[v][0] = prev;
    pref[v] = pref[prev] + w[v];
    // cout << pref[v] << '\n';
    for(ll i = 1; i <= l; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for(ll u : g[v]) {
        if(u != prev) {
            dfs(u, v);
        }
    }
    tout[v] = t++;
}

bool check(ll u, ll v) {
    return tin[u] <= tin[v] && tin[v] < tout[u];
}

ll lca(ll u, ll v) {
   if(check(u, v)) return u;
   if(check(v, u)) return v;
   for(ll i = l; i > -1; i--)
       if(!check(up[u][i], v)) u = up[u][i];
   return up[u][0];
}

int main() {
    ll n, m;
    cin >> n;
    l = 19;
    for(ll i = 0; i < n; i++)
        cin >> w[i];
    for(ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    // for(ll i = 0; i < n; i++) cout << pref[i] << ' ';
    cin >> m;
    while(m--) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        ll u = lca(x, y);
        cout << pref[x] - (u != 0 ? pref[up[u][0]] : 0) + pref[y] - pref[u] << '\n';
    }
}
