#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second

ll inf = 1e16;
ll colors[100000];

void dfs(ll v, vector<vll> & g, ll color) {
    colors[v] = color;
    for(ll u : g[v]) {
        if(!colors[u])
            dfs(u, g, -color);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vll> g(n);
    set<ll> f;
    while(m--) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
        f.insert(v), f.insert(u);
    }
    if(f.size() != n) cout << -1 << '\n', exit(0);
    for(ll i = 0; i < n; i++) {
        if(!colors[i])
            dfs(i, g, 1);
    }
    for(ll i = 0; i < n; i++) {
        if(colors[i] < 0) cout << 2 << ' ';
        else cout << 1 << ' ';
    }
}
