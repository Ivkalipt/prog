#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

void path(ll i, ll j, vvll & dp, vll & w, vll & ans) {
    if(dp[i][j] == 0) return;
    if(dp[i - 1][j] == dp[i][j]) path(i - 1, j, dp, w, ans);
    else path(i - 1, j - w[i], dp, w, ans), ans.push_back(i);
}

int main() {
    fastio;
    ll n, W;
    cin >> n >> W;
    vll w(n + 1, 0), c(n + 1, 0);
    for(ll i = 1; i <= n; i++) cin >> w[i];
    for(ll i = 1; i <= n; i++) cin >> c[i];
    vvll dp(n + 1, vll(W + 1, 0));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + c[i]);
        }
    }
    vll ans;
    path(n, W, dp, w, ans);
    cout << ans.size() << '\n';
    for(ll & v : ans) cout << v << ' ';
    cout << '\n';
}
