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
    ll n, W;
    cin >> n >> W;
    vll w(n);
    for (ll & c : w) cin >> c;
    vvll dp(n + 1, vll(W + 1, 0));
    dp[0][0] = 1;
    rep(i, 1, n + 1) {
        rep(j, 0, W + 1) {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i - 1] && dp[i - 1][j - w[i - 1]])
                dp[i][j] = true;
        }
    }

    for (ll i = W; i > -1; i--) {
        if (dp[n][i]) {
            cout << i << '\n';
            return 0;
        }
    }
}