#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

struct edge {
    ll v, u;
    ld p;
};

int main() {
    ll n, m, s, f;
    cin >> n >> m >> s >> f;
    s--, f--;
    vector<edge> edges;
    for(ll i = 0; i < m; i++) {
        ll v, u;
        ld p;
        cin >> v >> u >> p;
        v--, u--, p /= 100;
        edges.push_back({v, u, 1 - p});
        edges.push_back({u, v, 1 - p});
    }
    vector<ld> d(n, 0);
    d[s] = 1;
    for(ll k = 0; k < n; k++) {
        for(auto && [v, u, p] : edges) {
            d[u] = max(d[u], d[v] * p);
        }
    }
    cout << 1 - d[f] << '\n';
}
