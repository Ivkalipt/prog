#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<long long>;

const ll maxn = 1e5 + 10, logn = 30; 
ll tin[maxn], tout[maxn], up[maxn][logn];
vll g[maxn];
ll t = 0;

void dfs(ll v, ll prev) {
    tin[v] = t++;
    up[v][0] = prev;
    for(ll i = 1; i < logn; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1]; 
    }
    for(ll u : g[v]) {
        if(u != prev) dfs(u, v);
    }
    tout[v] = t++;
}

bool check(ll u, ll v) {
    return tin[u] <= tin[v] && tin[v] < tout[u];
}

ll lca(ll u, ll v) {
   if(check(u, v)) return u;
   if(check(v, u)) return v;
   for(ll i = logn - 1; i > -1; i--)
       if(!check(up[u][i], v)) u = up[u][i];
   return up[u][0];
}

int main() {
    ll n;
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll root = 0;
    dfs(root, 0);
    ll m;
    char type;
    cin >> m >> type;
    while(type != '0') {
        if(type == '!') {
            ll u;
            cin >> u;
            root = u - 1;
        } else {
            ll u, v;
            cin >> u >> v;
            u--, v--;
            ll a = lca(u, v) + 1;
            ll b = lca(u, root) + 1;
            ll c = lca(v, root) + 1;
            cout << (a ^ b ^ c) << '\n';
        }
        cin >> type;
    }
}
