#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()
#define F first
#define S second

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

const ll maxn = 1e5;
ll p[maxn], rk[maxn], level[maxn];
bool used[maxn];

struct Edge {
  ll v, u, w;
};

// bool operator<(const pll a, const pll b) { return a.S < b.S; }

ll leader(ll v) { return p[v] == v ? v : p[v] = leader(p[v]); }

void unite(ll v, ll u) {
  v = leader(v), u = leader(u);
  if (rk[v] > rk[u])
    swap(u, v);
  rk[u] = max(rk[u], rk[v] + 1);
  p[v] = u;
  /*level[u] += level[v];
  level[v] = 0;**/
}

void init(ll n, vll &a) {
  for (ll i = 0; i < n; i++)
    p[i] = i, rk[i] = 1 /*, level[i] = a[i]*/;
}

int main() {
  ll n, m, s;
  cin >> n >> m >> s;
  s--;
  vll a(n);
  vector<vector<pll>> g(n);
  for (ll &c : a)
    cin >> c;
  for (ll i = 0; i < m; i++) {
    ll v, u, w;
    cin >> v >> u >> w;
    v--, u--;
    g[v].push_back({u, w});
    g[u].push_back({v, w});
  }
  set<pll> q;
  for (pll u : g[s]) {
    q.insert({u.F, u.S});
  }
  for (pll c : q)
    cout << c.F << ':' << c.S << '/';
  cout << '\n';

  ll levelcur = a[s];
  used[s] = true;
  while (!q.empty()) {
    for (pll c : q)
      cout << c.F << ':' << c.S << '/';
    cout << '\n';
    pll p = *q.begin();
    q.erase(*q.begin());
    ll v = p.F, w = p.S;
    if (used[v])
      continue;
    if (w <= levelcur) {
      levelcur += a[v];
      used[v] = true;
      for (auto [u, w] : g[v]) {
        if (!used[u])
          q.insert({u, w});
      }
    } else
      break;
  }
  cout << levelcur << '\n';
}
