#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

bool used[10000];
vll tops;
ll colors[10000];

void dfs(ll v, vvll & g) {
    used[v] = true;
    for(ll u : g[v]) {
        if(!used[u]) dfs(u, g);
    }
    tops.push_back(v);
}

void dfs(ll v, vvll & g, ll color) {
    used[v] = true;
    colors[v] = color;
    for(ll u : g[v]) {
        if(!used[u]) dfs(u, g, color);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vvll g1(n), g2(n);
    vpll edges(m);
    for(ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        g1[v].push_back(u);
        g2[u].push_back(v);
        edges[i] = {v, u};
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i]) dfs(i, g1);
    }
    reverse(all(tops));
    // vll pred(n);
    for(ll i = 0; i < n; i++) used[i] = 0;
    ll color = 0;
    for(ll v : tops) {
        if(!used[v]) {
            dfs(v, g2, color);
            // pred[color] = v;
            color++;
        }
    }
    vector<bool> usedCol(color, 1);
    for(pll edge : edges)
        if(colors[edge.F] != colors[edge.S]) usedCol[colors[edge.F]] = 0;
    ll cnt = 0;
    for(ll i = 0; i < color; i++)
        if(usedCol[i]) cnt++;
    cout << cnt << '\n';
    /*for(ll i = 0; i < color; i++)
        if(usedCol[i]) cout << pred[i] << '\n';
    
    cout << color << '\n';*/
}
