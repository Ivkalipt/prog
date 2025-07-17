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

const ll inf = 1e18, t = 1440, massLorry = 3 * 1e6, massCup = 1e2;

vll d;

void dijkstra(ll s, vector<vector<pll>> & g, map<pll, ll> & cs, ll mass) {
    set<pll> q;
    d[s] = 0;
    q.insert({d[s], s});
    while (!q.empty()) {
        ll v = q.begin()->S;
        q.erase(*q.begin());
        for (auto [w, u] : g[v]) {
            if (d[u] > d[v] + w && cs[{u, v}] >= mass) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                q.insert({d[u], u});
            }
        }
    }
}

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    map<pll, ll> cs;
    vector<vector<pll>> g(n);
    while (m--) {
        ll v, u, w, c;
        cin >> v >> u >> w >> c;
        v--, u--;
        g[v].push_back({w, u});
        g[u].push_back({w, v});
        cs[{u, v}] = c;
        cs[{v, u}] = c;
    }
    d.resize(n, inf);
    ll l = 0, r = 1e7 + 1;
    while (r - l > 1) {
        ll mid = (r + l) / 2;
        d.assign(n, inf);
        dijkstra(0, g, cs, mid * massCup + massLorry);
        if (d[n - 1] > t) {
            r = mid;
        } else {
            l = mid;
        }
        // cout << l << ' ' << r << ' ' << mid * massCup + massLorry << '\n';
    }
    cout << l;
}
