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

ll used[MAXN], dp[MAXN];
ll cnt = 0;
bool f = 0;

void dfs(ll v, vvll & g) {
  used[v] = true;
  cnt++;
  if (cnt > 1e6) {
    f = 1;
    return;
  }
  for (ll u : g[v]) {
    if (!used[u]) {
      dfs(u, g);
    }
  }
  used[v] = false;
}

int main() {
  ll n, m;
  cin >> n >> m;
  vvll g(n);
  while (m--) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[v].pb(u);
    g[u].pb(v);
  }
  dfs(0, g);
  if (f) cout << 1'000'000 << '\n';
  else cout << cnt << '\n';
  return 0;
}
