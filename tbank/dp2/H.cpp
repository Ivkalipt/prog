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

constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll & x : a) cin >> x;
    ll s;
    cin >> s;
    vector dp(s + 1, INF);
    vector p(s + 1, pll(-1, -1));
    dp[0] = 0;
    for (ll i = 1; i <= s; i++) {
        for (ll j = 0; j < n; j++) {
            if (a[j] <= i && dp[i] > dp[i - a[j]] + 1) {
                dp[i] = dp[i - a[j]] + 1;
                p[i] = {i - a[j], a[j]};
            }
        }
    }
    if (dp[s] == INF) {cout << -1 << '\n'; return 0;}
    pll ind = {s, -1};
    vll ans;
    while (ind.F != -1) {
        ans.push_back(p[ind.F].S);
        ind = p[ind.F];
    }
    ans.pop_back();
    for (ll x : ans) cout << x << ' ';
    cout << '\n';

}
