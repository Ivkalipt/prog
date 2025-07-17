#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e16, maxn = 2e5;

ll parent[maxn], rang[maxn];

ll p[maxn], s[maxn];

struct DSU {
  vector<ll> parent, sz;
  vector<long long> add, delta;

  DSU(ll n) : parent(n + 1), sz(n + 1, 1), add(n + 1, 1), delta(n + 1, 0) {
    iota(parent.begin(), parent.end(), 0);
  }

  ll find(ll v) {
    if (parent[v] == v)
      return v;
    ll p = find(parent[v]);
    delta[v] += delta[parent[v]];
    return parent[v] = p;
  }

  void unite(ll a, ll b) {
    ll ra = find(a), rb = find(b);
    if (ra == rb)
      return;

    ++add[ra];
    ++add[rb];

    if (sz[ra] < sz[rb])
      swap(ra, rb);

    parent[rb] = ra;
    delta[rb] = add[rb] - add[ra];
    sz[ra] += sz[rb];
  }

  bool same(ll a, ll b) { return find(a) == find(b); }

  long long count(ll v) {
    ll r = find(v);
    return delta[v] + add[r];
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;

  DSU dsu(n);

  for (ll i = 0; i < m; ++i) {
    ll type;
    cin >> type;
    if (type == 1) {
      ll x, y;
      cin >> x >> y;
      dsu.unite(x, y);
    } else if (type == 2) {
      ll x, y;
      cin >> x >> y;
      cout << (dsu.same(x, y) ? "YES\n" : "NO\n");
    } else if (type == 3) {
      ll x;
      cin >> x;
      cout << dsu.count(x) << '\n';
    }
  }
  return 0;
}
