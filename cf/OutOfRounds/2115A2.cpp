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

const ll INF = 1e18;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll & x : a) cin >> x;

    ll g = a[0];
    for (const ll & x : a)
        g = gcd(g, x);
    ll cntg = count(all(a), g);
    if (cntg) { cout << n - cntg << '\n'; return; }

    vector<pll> dp(n);
    for (ll i = 0; i < n; i++)
        dp[i] = {a[i], 1};

    for (ll i = 0; i < n; i++) {
        ll min_gcd = dp[i].F, min_len = dp[i].S;
        for (ll j = 0; j < n; j++) {
            ll now_gcd = __gcd(dp[j].F, a[i]);
            if (now_gcd < min_gcd || (now_gcd == min_gcd && dp[j].S < min_len))
                min_gcd = now_gcd, min_len = dp[j].S;

        }
        dp[i] = {min_gcd, min(min_len + 1, dp[i].S)};
    }
    // for (pll x : dp) cout << x.F << ' ' << x.S << '\n';
    ll min_size = INF;
    for (ll i = 0; i < n; i++)
        if (dp[i].F == g && dp[i].S < min_size) min_size = dp[i].S;
    ll ans = min_size - 1;
    for (ll i = 0; i < n; i++) {
        if (a[i] != g) ans++;
    }
    cout << ans - 1 << '\n';
}

int main() { ll t; cin >> t; while (t--) solve(); }