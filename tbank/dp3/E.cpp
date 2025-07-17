#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll maxn = 2e5;

vll g[maxn];
ll dp[maxn], cnt[maxn];

void dfs1(ll v, ll prev) {
    cnt[v] = 1;
    for(ll u : g[v]) {
        if(u != prev) {
            dfs1(u, v);
            cnt[v] += cnt[u];
        }
    }
}

void dfs2(ll v, ll prev) {
    dp[v] = cnt[v];
    for(ll u : g[v]) {
        if(u != prev) {
            dfs2(u, v);
            dp[v] += dp[u];
        }
    }
}

int main() {
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++) {
        ll v;
        cin >> v, v--;
        g[v].push_back(i);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    for(ll i = 0; i < n; i++) cout << dp[i] << ' ';

}
