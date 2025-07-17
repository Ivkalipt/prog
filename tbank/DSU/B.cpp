#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e16, maxn = 2e5;

ll p[maxn], s[maxn];

struct edge {
    ll v, u, w;
};

ll leader(ll v) {
    return (p[v] == v) ? v : p[v] = leader(p[v]);
}

void unite(ll v, ll u) {
    ll a = leader(v), b = leader(u);
    if(s[a] > s[b])
        swap(a, b);
    s[b] += s[a];
    p[a] = b;
}

void init(ll n) {
    for(ll i = 0; i < n; i++) {
        p[i] = i, s[i] = 1;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    init(n);
    vector<edge> edges(m);
    for(auto && [v, u, w] : edges) cin >> v >> u >> w;
    sort(all(edges), [&] (edge a, edge b) {
        return a.w < b.w;
            });
    ll ans = 0;
    init(n);
    for(auto [v, u, w] : edges) {
        //cout << v << ' ' << u << ' ' << w << '\n';
        if(leader(v) != leader(u)) unite(v, u), ans += w;
    }
    cout << ans << '\n';
}

