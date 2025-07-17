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

vll d;

void bfs(vll s, vector<vll> & g) {
    queue<ll> q;
    for(ll c : s) q.push(c), d[c] = 0;
    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        for(ll u : g[v]) {
            if(d[u] <= d[v] + 1) continue;
            d[u] = d[v] + 1;
            q.push(u);
        }
    }
}

int main() {
    fastio;
    ll n, k, m;
    cin >> n >> k;
    vll outs(k);
    for(ll & c : outs) cin >> c, c--;
    cin >> m;
    vector<vll> g(n);
    while(m--) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    d.resize(n, inf);
    bfs(outs, g);
    for(ll c : d) cout << c << ' ';
    cout << "\n";
    return 0;
}
