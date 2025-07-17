#include <tuple>
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i <= (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18, MOD = 1e9 + 7;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> a(n);
  vvll l(m + 10), r(m + 10);
  for (ll i = 0; i < n; i++) {
    ll lx, rx, cx;
    cin >> lx >> rx >> cx;
    a[i] = {lx, rx, cx};
    l[lx].push_back(i);
    r[rx].push_back(i);
  }
  vll dp(m + 10, INF);
  dp[0] = 0;
  for (ll i = 1; i <= m + 1; i++) { // идем по точкам, dp[i] стоимость до i вкл.
    for (ll seg :
         r[i]) { // идем по отрезкам, которые кончаются в i, seg - номер
      // dp[i] = min(dp[get<0>(a[seg])] + get<2>(a[seg]), dp[i]);
      ll min_last = dp[get<0>(a[seg])];
      for (ll j = get<0>(a[seg]) + 1; j <= i; j++) {
        min_last = min(min_last, dp[j]);
      }
      dp[i] = min(min_last + get<2>(a[seg]), dp[i]);
    }
  }
  for (ll c : dp)
    cout << c << ' ';
  cout << '\n';
}
