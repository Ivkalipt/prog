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
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 2e5;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vpll ores(n);
  for (pll & x : ores) cin >> x.F >> x.S;
  vector dp(a + 1, vector(b + 1, INF));
  dp[0][0] = 0;
  for (const pll & x : ores) {
    for (ll i = a; i >= 0; i--) {
      for (ll j = b; j >= 0; j--) {
        ll to_i = min(a, i + x.F);
        ll to_j = min(b, j + x.S);
        dp[to_i][to_j] = min(dp[to_i][to_j], dp[i][j] + 1);
      }
    }
  }
  /*for (vll x1 : dp) {
    for (ll x2 : x1) cout << x2 << ' ';
    cout << '\n';
  }*/
  cout << (dp[a][b] == INF ? -1 : dp[a][b]) << '\n';
}
