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

const ll maxn = 1e2 + 2, inf = 1e18;

ll dp[maxn][maxn], a[maxn];

ll rec(ll l, ll r) {
    if(dp[l][r] != inf) return dp[l][r];
    if(l == r || l + 1 == r) {
        dp[l][r] = 0;
        return dp[l][r];
    }
    for(ll k = l + 1; k < r; k++) {
        dp[l][r] = min(dp[l][r], rec(l, k) + rec(k, r) + a[r] - a[l]);
        // cout << l << ' ' << k << ' ' << r << '\n';
    }
    return dp[l][r];
}

int main() {
    for(ll i = 0; i < maxn; i++) {
        for(ll j = 0; j < maxn; j++) dp[i][j] = inf;
    }
    ll l, n;
    cin >> l >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = l;
    cout << rec(0, n + 1) << '\n';
}
