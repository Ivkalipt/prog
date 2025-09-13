#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;

int main() {
  ll n;
  cin >> n;
  vll p(n), q(n);
  ll max_money = 0;
  for (ll & x : p) cin >> x, max_money += x;
  for (ll & x : q) cin >> x, max_money += x;
  ll ans = 0;
  for (ll center : {0, 1}) {
    vector dp(n + 1, vector(2, 0LL));
    dp[0][0] = max_money - (1 - center) * p[0];
    dp[0][1] = max_money - center * p[0];
    for (ll i = 1; i < n; i++) {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + q[i - 1]) - (1 - center) * p[i];
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + q[i - 1]) - center * p[i];
    }
    dp[n][0] = min(dp[n - 1][0], dp[n - 1][1] + q[n - 1]) - (1 - center) * p[n - 1];
    dp[n][1] = min(dp[n - 1][1], dp[n - 1][0] + q[n - 1]) - center * p[n - 1];
    ans = max({ans, dp[n][0], dp[n][1]});
    for (ll i = 0; i <= n; i++)
      cout << dp[i][0] << ' ';
    cout << '\n';
    for (ll i = 0; i <= n; i++)
      cout << dp[i][1] << ' ';
    cout << '\n';
  }
  cout << ans << '\n';
}
