#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll maxn = 2e5;
ll p[maxn], rk[maxn], expir[maxn];

ll leader(ll v) {
  if (p[v] == v)
    return v;
  else
    return leader(p[v]);
}

void unite(ll v, ll u) {
  v = leader(v), u = leader(u);
  if (rk[v] > rk[u])
    swap(u, v);
  if (v == u)
    return;
  rk[u] = max(rk[u], rk[v] + 1);
  p[v] = u;
  expir[v] -= expir[u];
}

void init(ll n) {
  for (ll i = 0; i < n; i++)
    p[i] = i, rk[i] = 1;
}

void add(ll v, ll x) { expir[leader(v)] += x; }

ll get(ll v) {
  if (p[v] == v)
    return expir[v];
  else
    return get(p[v]) + expir[v];
}

int main() {
  ll n, m;
  cin >> n >> m;
  init(n);
  while (m--) {
    string type;
    cin >> type;
    if (type == "add") {
      ll v, x;
      cin >> v >> x;
      v--;
      add(v, x);
    } else if (type == "join") {
      ll v, u;
      cin >> v >> u;
      v--, u--;
      unite(v, u);
    } else {
      ll v;
      cin >> v;
      v--;
      cout << get(v) << '\n';
    }
  }
}
