#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<long long>;

const ll inf = 1e5 + 10;
ll tin[inf], tout[inf], up[inf][20];
vll g[inf];
ll t = 0, l;

void dfs(ll v, ll prev) {
    tin[v] = t++;
    up[v][0] = prev;
    for(ll i = 1; i <= l; i++) {
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
   for(ll i = l; i > -1; i--)
       if(!check(up[u][i], v)) u = up[u][i];
   return up[u][0];
}

int main() {
    ll n, m;
    cin >> n >> m;
    l = 1;
    while((1 << l) <= n) l++;
    for(ll i = 1; i < n; i++) {
        ll v;
        cin >> v;
        g[v].push_back(i);
        g[i].push_back(v);
    }
    ll a1, a2, x, y, z;
    cin >> a1 >> a2 >> x >> y >> z;
    ll v = 0, s = 0;
    dfs(0, 0);
    for(ll i = 0; i < m; i++) {
        v = lca((a1 + v) % n, a2);
        s += v;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }
    cout << s << '\n';
}
