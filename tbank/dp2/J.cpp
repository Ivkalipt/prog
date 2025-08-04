#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 9;

ll rec(ll l, ll r, vvll & dp, string & s) {
    // cout << '!';
    if (dp[l][r] != INF) return dp[l][r];
    if (l > r) return INF;
    if (l == r) dp[l][r] = 0;
    else if (r - l == 1) dp[l][r] = (s[l] == s[r] ? 0 : 1);
    else dp[l][r] = rec(l + 1, r - 1, dp, s) + (s[l] == s[r] ? 0 : 1);
    return dp[l][r];
}

int main() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector dp(n, vector (n, INF));
    for (ll l = 0; l < n; l++) {
        for (ll r = l; r < n; r++) {
            dp[l][r] = rec(l, r, dp, s);
        }
    }
    ll cnt = 0;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (dp[i][j] <= k) cnt++;
        }
    }
    cout << cnt << '\n';
}
