#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

bool used[100000];
vll tin, tout;
ll t = 0;

void dfs(ll v, vector<vll> & g) {
    used[v] = 1;
    tin[v] = t++;
    for(ll u : g[v])
        if(!used[u]) dfs(u, g);
    tout[v] = t++;
}

int main() {
    ll n, s;
    cin >> n;
    vector<vll> g(n);
    for(ll i = 0; i < n; i++) {
        ll v;
        cin >> v;
        if(v == 0)
            s = i;
        else
            g[v - 1].push_back(i);

    }
    tin.resize(n), tout.resize(n);
    dfs(s, g);
    ll m;
    cin >> m;
    while(m--) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        if(tin[a] < tin[b] && tout[b] < tout[a]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}
