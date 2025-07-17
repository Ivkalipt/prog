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
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

struct edge {
    ll v, u, w;
};

vector<bool> used;

void dfs(ll v, vector<vll> & g) {
    used[v] = true;
    for(ll u : g[v]) {
        if(!used[u])
            dfs(u, g);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<edge> g(m);
    vector<vll> g2(n);
    for(ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[i] = {v, u, -w};
        g2[v].push_back(u);
    }
    vll dp(n, inf);
    dp[0] = 0;
    for(ll k = 0; k < n; k++) {
        for(auto [v, u, w] : g) {
            if(dp[v] != inf && dp[v] + w < dp[u]) 
                dp[u] = dp[v] + w;
        }
    }
    vll dp2 = dp;
    for(auto [v, u, w] : g) {
        if(dp2[v] != inf && dp2[v] + w < dp2[u]) 
            dp2[u] = dp2[v] + w;
    }
    for(ll i = 0; i < n; i++) {
        if(dp2[i] < dp[i]) {
            used.assign(n, 0);
            dfs(i, g2);
            if(used[n - 1]) cout << ":)\n", exit(0);
        }
    }
    // ll dn = dp[n - 1];
    if(dp[n - 1] == inf) cout << ":(\n";
    // else if(dn > dp[n - 1]) cout << ":)\n";
    else cout << -dp[n - 1] << '\n';

}
