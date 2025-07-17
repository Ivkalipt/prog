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

const ll inf = 3e4;
vll dp;

struct edge {
    ll v, u, w;
};

void ford(ll s, vector<edge> & g, ll n) {
    dp[s] = 0;
    for(ll i = 0; i < n; i++) {
        for(auto [a, b, w] : g) {
            if(dp[a] != inf && dp[a] + w < dp[b]) {
                dp[b] = dp[a] + w;
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<edge> g(m);
    dp.resize(n, inf);
    for(ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[i] = {u, v, w};
    }
    ford(0, g, n);
    for(ll c : dp) cout << c << ' ';
    cout << '\n';
}
