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

int main() {
    ll n, m, k, s, f;
    cin >> n >> m >> k >> s >> f;
    s--, f--;
    vector<edge> g(m);
    for(ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[i] = {v, u, w};
    }
    vector<vll> dp(k + 1, vll(n, inf));
    dp[0][s] = 0;
    for(ll i = 1; i <= k; i++) {
        for(auto [v, u, w] : g) {
            if(dp[i - 1][v] + w < dp[i][u] && dp[i - 1][v] != inf) {
                dp[i][u] = dp[i - 1][v] + w;
            }
        }
    }
    ll ans = inf;
    for(ll i = 0; i <= k; i++) {
        ans = min(ans, dp[i][f]);
    }
    cout << (ans == inf ? -1 : ans) << '\n';
}
