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

struct vertex {
    ll dist, num, p;
};

bool operator < (vertex a, vertex b) {
    return a.dist < b.dist || (a.dist == b.dist && a.num < b.num); // Пиздец, нахуя их сортить так. Нихуя же от этого не зависит
}

const ll inf = 1e18;
vector<vll> d;
vll par(100, -1);

void dijkstra(ll s, vector<vll> & g, vll & a) {
    d[0][s] = 0;
    d[1][s] = a[s];
    set<vertex> q;
    q.insert({d[0][s], s, 0});
    q.insert({d[0][s], s, 1});
    while(!q.empty()) {
        ll dist = q.begin()->dist;
        ll v = q.begin()->num;
        ll p = q.begin()->p;
        q.erase(*q.begin());
        for(ll u : g[v]) {
            if(p == 1 && d[p - 1][u] > dist) {
                q.erase({d[p - 1][u], u, p - 1});
                d[p - 1][u] = dist;
                q.insert({d[p - 1][u], u, p - 1});
            }
            if(p == 1 && d[p][u] > dist + a[v]) {
                q.erase({d[p][u], u, p});
                d[p][u] = dist + a[v];
                q.insert({d[p][u], u, p});
            }

            if(p == 0 && d[p][u] > dist + a[v]) {
                q.erase({d[p][u], u, p});
                d[p][u] = dist + a[v];
                q.insert({d[p][u], u, p});
            }
            if(p == 0 && d[p + 1][u] > dist + 2 * a[v]) {
                q.erase({d[p + 1][u], u, p + 1});
                d[p + 1][u] = dist + 2 * a[v];
                q.insert({d[p + 1][u], u, p + 1});
            }
        }
        // for(vertex c : q) cout << c.dist << ' ';
        // cout << '\n';
    }
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    ll m;
    cin >> m;
    vector<vll> g(n);
    d.resize(2, vll(n, inf));
    for(ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dijkstra(0, g, a);
    /* for(ll i = 0; i < n; i++) {
        for(ll c : d[i]) {
            cout << c << ' ';
        }
        cout << '\n';
    }*/
    ll ans = min({d[0][n - 1], d[1][n - 1]});
    cout << (ans == inf ? -1 : ans) << '\n';

}
