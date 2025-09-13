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
  fastio;
  ll n;
  cin >> n;
  vll p(n), q(n);
  for (ll & x : p) cin >> x;
  for (ll & x : q) cin >> x;

  vector dp(n, vector(2, 0LL));

  // 0
  dp[0][0] = p[0];
  dp[0][1] = INF;

  for (ll i = 1; i < n; i++) {
    dp[i][0] = min(dp[i - 1][0] + q[i - 1], dp[i - 1][1]) + p[i];
    dp[i][1] = min(dp[i - 1][1] + q[i - 1], dp[i - 1][0]);
  }
  ll c1 = min(dp[n - 1][0] + q[n - 1], dp[n - 1][1]);

  /*for (ll i = 0; i <= n; i++)
    cout << dp[i][0] << ' ';
  cout << '\n';
  for (ll i = 0; i <= n; i++)
    cout << dp[i][1] << ' ';
  cout << '\n';*/


  // 1
  dp[0][0] = INF;
  dp[0][1] = 0;

  for (ll i = 1; i < n; i++) {
    dp[i][0] = min(dp[i - 1][0] + q[i - 1], dp[i - 1][1]) + p[i];
    dp[i][1] = min(dp[i - 1][1] + q[i - 1], dp[i - 1][0]);
  }
  ll c2 = min(dp[n - 1][0], dp[n - 1][1] + q[n - 1]);

  cout << min(c1, c2) << '\n';

  /*for (ll i = 0; i <= n; i++)
    cout << dp[i][0] << ' ';
  cout << '\n';
  for (ll i = 0; i <= n; i++)
    cout << dp[i][1] << ' ';
  cout << '\n';*/

  // cout << ans << '\n';
}
