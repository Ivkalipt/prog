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

ll p[maxn], s[maxn];

struct query {
  string t;
  ll v, u;
};

ll leader(ll v) { return (p[v] == v) ? v : p[v] = leader(p[v]); }

void unite(ll v, ll u) {
  ll a = leader(v), b = leader(u);
  if (s[a] > s[b])
    swap(a, b);
  s[b] += s[a];
  p[a] = b;
}

void init(ll n) {
  for (ll i = 0; i < n; i++) {
    p[i] = i, s[i] = 1;
  }
}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  init(n);
  vector<pair<ll, ll>> e(m);
  for (auto c : e)
    cin >> c.first >> c.second;
  vector<query> queries(k);
  vector<string> anses;
  for (auto &&[t, v, u] : queries)
    cin >> t >> v >> u;
  reverse(all(queries));
  for (auto [t, v, u] : queries) {
    if (t == "cut")
      unite(v, u);
    else {
      anses.push_back(leader(v) == leader(u) ? "YES" : "NO");
    }
  }
  reverse(all(anses));
  for (string s : anses)
    cout << s << '\n';
}
