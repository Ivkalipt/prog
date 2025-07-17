#include <algorithm>
#pragma GCC optimize("O3,unroll-loops")
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

const ll maxn = 1e5;

ll w[maxn], w1[maxn];

void dfs(ll v, vector<vll> & g, vll & tops, vector<bool> & used) {
    used[v] = true;
    for(ll u : g[v]) {
        if(!used[u]) dfs(u, g, tops, used);
    }
    tops.push_back(v);
}

void dfs(ll v, vector<vll> & g, vll & col, ll color, ll & sumw) {
    sumw += w[v]; 
    col[v] = color;
    for(ll u : g[v]) {
        if(col[u] == -1) dfs(u, g, col, color, sumw);  
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vll col(n, -1);
    vector<vll> g(n), gt(n), gscc(n), gscct(n);
    for(ll i = 0; i < n; i++) cin >> w[i];
    for(ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        gt[u].push_back(v);
    }

    vll tops;
    vector<bool> used(n);
    for(ll i = 0; i < n; i++) {
        if(!used[i]) dfs(i, g, tops, used);
    }

    reverse(all(tops));
    ll t = 0;
    for(ll v : tops) {
        if(col[v] == -1) {
            ll sumw = 0;
            dfs(v, gt, col, t, sumw);
            w1[t] = sumw;
            // cout << sumw << ' ';
            t++;
        }
    }
    cout << '\n';

    set<pll> ed;
    for(ll v = 0; v < n; v++) {
        for(ll u : g[v]) {
            if(col[v] != col[u]) ed.insert({col[v], col[u]});
        }
    }

    for(auto [v, u] : ed) {
        gscc[v].push_back(u);
        gscct[u].push_back(v);
        // cout << v + 1 << ' ' << u + 1 << '\n';
    }
    
    vll tops1;
    vector<bool> used1(n);
    for(ll i = 0; i < t; i++) {
        if(!used1[i]) dfs(i, gscc, tops1, used1);
    }
    /*for(ll i = 0; i < 4; i++) {
        cout << w1[i] << ' ';
    }
    for(ll c : tops1) {
        cout << c << ' ';
    }*/
    reverse(all(tops1));
    vll dp(n);
    for(ll v : tops1) {
        // cout << v + 1 << ' ';
        ll mx = 0;
        for(ll u : gscct[v]) {
            mx = max(mx, dp[u]);
        }
        dp[v] = mx + w1[v];
    }
    cout << *max_element(all(dp));
}

