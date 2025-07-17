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

const ll inf = 1e18;

ll p[5000];
vll d;

void dijkstra(vll & a, vector<vector<pll>> & g) {
    set<pll> q;
    for(ll i = 0; i < a.size(); i++) {
        if(a[i] == 1) p[i] = i, d[i] = 0, q.insert({d[i], i});
    }
    while(!q.empty()) {
        ll v = q.begin()->S;
        q.erase(*q.begin());
        for(auto [w, u] : g[v]) {
            if(d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                p[u] = p[v];
                q.insert({d[u], u});
            }
        }
    }

}

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vll a(n);
    d.resize(n, inf);
    for(ll & c : a) cin >> c;
    vector<vector<pll>> g(n);
    for(ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].push_back({w, u});
        g[u].push_back({w, v});
    }
    dijkstra(a, g);
    ll mind = inf, minx, miny;
    for(ll i = 0; i < n; i++) {
        if(a[i] == 2 && d[i] < mind) mind = d[i], minx = i, miny = p[i];
    }
    if(mind == inf) cout << -1 << '\n';
    else cout << miny + 1 << ' ' << minx + 1 << ' ' << mind << '\n';

}
