#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

bool used[100000];
vll d;

void bfs(ll v, vvll & g) {
    queue<ll> q;
    used[v] = 1;
    d[v] = 0;
    q.push(v);
    while(!q.empty()) {
        ll s = q.front();
        q.pop();
        for(ll u : g[s]) {
            if(used[u]) continue;
            used[u] = 1;
            d[u] = d[s] + 1;
            q.push(u);
        }
    }
}

int main() {
    fastio;
    ll n, m, s;
    cin >> n >> m >> s;
    s--;
    d.resize(n, -1);
    vvll g(n);
    while(m--) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(s, g);
    for(ll c : d) cout << c << ' ';
    cout << "\n";
    return 0;
}
