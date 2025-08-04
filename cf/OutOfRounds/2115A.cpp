#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e9 + 7;
constexpr ll N = 5e3;

ll GCD[N + 1][N + 1];

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll & x : a) cin >> x;
    vll dp(N + 1, INF);
    dp[0] = 0;
    ll g = a[0];
    for (const ll & x : a)
        g = gcd(g, x);
    ll cntg = count(all(a), g);
    if (cntg) {
        cout << n - cntg << '\n';
        return;
    }

    vll new_dp = dp;
    for (ll i = 0; i < n; i++) {
        vll current_dp = new_dp;
        for (ll x = 0; x <= N; x++) {
            if (current_dp[x] == INF) continue;
            ll y = GCD[a[i]][x];
            if (new_dp[y] > current_dp[x] + 1) {
                new_dp[y] = current_dp[x] + 1;
            }
        }
    }
    dp = new_dp;

    cout << dp[g] + n - 2 << '\n';
}
int main() {
    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; j <= N; j++) {
            GCD[i][j] = gcd(i, j);
        }
    }
    fastio;
    ll t;
    cin >> t;
    while (t--) solve();
}