#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll maxn = 1e5;
ll p[maxn], rk[maxn];

ll leader(ll v) { return p[v] == v ? v : p[v] = leader(p[v]); }

void unite(ll v, ll u) {
  v = leader(v), u = leader(u);
  if (rk[v] > rk[u])
    swap(u, v);
  rk[u] = max(rk[u], rk[v] + 1);
  p[v] = u;
}

void init(ll n) {
  for (ll i = 0; i < n; i++)
    p[i] = i, rk[i] = 1;
}

int main() {}
