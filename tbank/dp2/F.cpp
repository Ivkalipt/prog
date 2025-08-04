#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    /*fastio;
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
    }*/
    ll n, w;
    cin >> n >> w;
    vll m(n), c(n);
    for (ll & x : m) cin >> x;
    for (ll & x : c) cin >> x;
    vvll dp(n + 1, vll(w + 1, 0));
    vector<vector<pll>> p(n + 1, vector<pll>(w + 1, {-1, -1}));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= w; j++) {
            dp[i][j] = dp[i - 1][j];
            p[i][j] = {i - 1, j};
            if (m[i - 1] <= j && dp[i - 1][j - m[i - 1]] + c[i - 1] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - m[i - 1]] + c[i - 1];
                p[i][j] = {i - 1, j - m[i - 1]};
            }
        }
    }
    pll ind = {n, w};
    vll ans;
    while (ind != pll(-1, -1)) {
        if (p[ind.F][ind.S].S != ind.S) ans.push_back(ind.F);
        ind = p[ind.F][ind.S];
    }
    ans.pop_back();
    cout << sz(ans) << '\n';
    for (ll x : ans) cout << x << " ";
    cout << '\n';

}
