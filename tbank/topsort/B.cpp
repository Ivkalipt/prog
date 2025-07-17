#include <algorithm>
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

void dfs(ll v, vector<vector<pll>> & g) {
    used[v] = true;
    for(pll u : g[v]) {
        if(!used[u.S]) dfs(u.S, g);
    }
    tops.push_back(v);
}

int main() {
    ll n, m, s, f;
    cin >> n >> m >> s >> f;
    s--, f--;
    vector<vector<pll>> g(n);
    while(m--) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].push_back({w, u});
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i]) dfs(i, g);
    } 
    reverse(all(tops));
    vll d(n, inf);
    d[s] = 0;
    for(ll i = 0; i < n; i++) {
        ll v = tops[i];
        for(pll u : g[v]) {
            if(d[v] == inf) continue;
            d[u.S] = min(d[u.S], d[v] + u.F);
        }
    }
    // for(ll c : d) cout << c << ' ';
    if(d[f] != inf) cout << d[f] << '\n';
    else cout << "Unreachable\n";
}
