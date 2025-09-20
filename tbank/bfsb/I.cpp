#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 5e3;

bool used[MAXN];

int main() {
  vector dist(MAXN, INF);

  ll n, m;
  cin >> n >> m;
  vector<int> type(n);
  vector<vpll> g(n);
  for (int & x : type) cin >> x;
  while (m--) {
    ll u, v, w;
    cin >> v >> u >> w;
    u--, v--;
    g[u].emplace_back(w, v);
    g[v].emplace_back(w, u);
  }

  set<tuple<ll, ll, ll>> q;
  for (ll i = 0; i < n; i++) {
    if (type[i] == 1) {
      q.insert({0, i, i});
      dist[i] = 0;
    }
  }

  while (!q.empty()) {
    auto [d, v, prev] = *q.begin();
    q.erase(*q.begin());
    for (auto [d1, u] : g[v]) {
      if (dist[u] > dist[v] + d1) {
        q.erase()
        dist[u] = dist[v] + d1;
        q.
      }
    }
  }
}
