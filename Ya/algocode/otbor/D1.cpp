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

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;

struct DSU {
  vll parent, rk;
  DSU(ll n) {
    parent.resize(n);
    rk.resize(n, 0);
    for (ll i = 0; i < n; i++) parent[i] = i;
  }
  ll find(ll u) {
    while (parent[u] != u) {
      u = parent[u];
    }
    return u;
  }
  bool unite(ll u, ll v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (rk[u] < rk[v]) {
      parent[u] = v;
    } else if (rk[u] > rk[v]) {
      parent[v] = u;
    } else {
      parent[v] = u;
      rk[u]++;
    }
    return true;
  }
};

struct LCA {
  ll n, logn;
  vvll parent;
  vvll dist;
  vll depth;
  LCA(const vector<vpll>& tree, ll root = 0) {
    n = tree.size();
    logn = log2(n) + 1;
    parent.resize(logn, vll(n));
    dist.resize(logn, vll(n));
    depth.resize(n);
    queue<ll> q;
    q.push(root);
    depth[root] = 0;
    parent[0][root] = root;
    dist[0][root] = 0;
    while (!q.empty()) {
      ll u = q.front(); q.pop();
      for (auto [v, w] : tree[u]) {
        if (v == parent[0][u]) continue;
        depth[v] = depth[u] + 1;
        parent[0][v] = u;
        dist[0][v] = w;
        q.push(v);
      }
    }
    for (ll k = 1; k < logn; k++) {
      for (ll i = 0; i < n; i++) {
        parent[k][i] = parent[k-1][parent[k-1][i]];
        dist[k][i] = dist[k-1][i] + dist[k-1][parent[k-1][i]];
      }
    }
  }
  ll query(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    ll distance = 0;
    for (ll k = logn-1; k >= 0; k--) {
      if (depth[u] - (1<<k) >= depth[v]) {
        distance += dist[k][u];
        u = parent[k][u];
      }
    }
    if (u == v) return distance;
    for (ll k = logn-1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        distance += dist[k][u] + dist[k][v];
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    distance += dist[0][u] + dist[0][v];
    return distance;
  }
};

int main() {
  fastio; 
  ll n, m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> edges;
  for (ll i = 0; i < m; i++) {
    ll u, v;
    ll w;
    cin >> u >> v >> w;
    u--; v--;
    edges.emplace_back(w, u, v);
  }
  sort(all(edges));
  DSU dsu(n);
  vector<vector<pair<ll, ll>>> tree(n);
  vector<bool> inMST(m, false);
  for (ll i = 0; i < m; i++) {
    auto [w, u, v] = edges[i];
    if (dsu.unite(u, v)) {
      inMST[i] = true;
      tree[u].emplace_back(v, w);
      tree[v].emplace_back(u, w);
    }
  }
  LCA lca(tree);
  ll ans = 0;
  for (ll i = 0; i < m; i++) {
    if (!inMST[i]) {
      auto [w, u, v] = edges[i];
      ll distance_in_tree = lca.query(u, v);
      ll candidate = min(w, distance_in_tree);
      if (candidate > ans) {
        ans = candidate;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
