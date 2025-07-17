#pragma GCC optimize("O3,unroll-loops")
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
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

vll tops;
bool used[100001];

void dfs1(ll v, vector<vll> & g) {
    used[v] = true;
    for(ll u : g[v]) {
        if(!used[u]) dfs1(u, g);
    }
    tops.push_back(v);
}

void dfs2(ll v, vector<vll> & g, vll & component) {
    used[v] = true;
    component.push_back(v);
    for(ll u : g[v]) {
        if(!used[u])
            dfs2(u, g, component);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vll> g1(n), g2(n);
    while(m--) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        g1[v].push_back(u);
        g2[u].push_back(v);
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i]) dfs1(i, g1);
    }
    reverse(all(tops));
    for(ll i = 0; i < n; i++) used[i] = 0;
    vector<pair<ll, vll>> components;
    ll t = 1;
    for(ll i = 0; i < n; i++) {
        ll v = tops[i];
        if(!used[v]) {
            vll component;
            dfs2(v, g2, component);
            components.push_back({t++, component});
        }
    }
    cout << t - 1 << '\n';
    vll ans(n);
    for(auto c : components) {
        for(ll cv : c.S) {
            ans[cv] = c.F;
        }
    } 
    for(ll c : ans) cout << c << ' ';
}
