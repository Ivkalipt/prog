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

const ll inf = 1e18, maxn = 1e6;
ll used[maxn], w[maxn], dp[maxn][2];
vll g[maxn];

void dfs(ll v, ll prev) {
    bool f = 0;
    for(ll u : g[v]) {
        if(u != prev) dfs(u, v), f = 1;
    }
    if(!f) dp[v][1] = w[v];
    else {
        ll sum0 = 0, sum1 = 0;
        for(ll u : g[v]) {
            if(u != prev) {
                sum0 += max(dp[u][1], dp[u][0]);
                sum1 += dp[u][0];
            }
        }
        dp[v][0] = sum0;
        dp[v][1] = sum1 + w[v];
    }

} 

int main() {
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> w[i];
    map<ll, ll> cnt;
    for(ll i = 0; i < n - 1; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
        cnt[u]++, cnt[v]++;
    }
    ll el = 0;
    for(pll c : cnt) if(c.S == 1) el = c.F;
    dfs(el, el);
    //for(ll i = 0; i < n; i++) cout << dp[i][1] << ' ' << dp[i][0] << '\n';
    cout << max(dp[el][0], dp[el][1]);
}
