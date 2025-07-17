#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
const ll inf = 1e9 + 1;

struct SegTree {

  vector<ll> t;
  ll n;
  void resize(ll sz) {
    n = 1;
    while (n < sz)
      n <<= 1;
    t.resize(2 * n - 1, 0);
  }

  void build(vll &a) {
    resize(a.size());
    build(a, 0, 0, n);
  }

  ll one(ll x) { return x; }

  ll cmp(ll a, ll b) { return a + b; }

  void build(vll &a, ll v, ll lx, ll rx) {
    if (rx - lx == 1 && lx < a.size()) {
      t[v] = one(a[lx]);
    } else if (rx - lx != 1) {
      ll m = (lx + rx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
      build(a, v1, lx, m);
      build(a, v2, m, rx);
      t[v] = cmp(t[v1], t[v2]);
    }
  }

  void set(ll i, ll x) { set(i, x, 0, 0, n); }

  void set(ll i, ll x, ll v, ll lx, ll rx) {
    if (rx - lx == 1) {
      t[v] = one(x);
      return;
    }
    ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
    if (m > i)
      set(i, x, v1, lx, m);
    else
      set(i, x, v2, m, rx);
    t[v] = cmp(t[v1], t[v2]);
  }

  ll get(ll l, ll r) { return get(l, r, 0, 0, n); }

  ll get(ll l, ll r, ll v, ll lx, ll rx) {
    if (lx >= r || rx <= l)
      return 0;
    if (l <= lx && r >= rx)
      return t[v];
    ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
    return cmp(get(l, r, v1, lx, m), get(l, r, v2, m, rx));
  }
};

int main() {
  ll n;
  cin >> n;
  vll a(n), even(n), odd(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (i + 1 & 1)
      even[i] = a[i];
    else
      odd[i] = a[i];
  }
  SegTree t, t1, t2;
  t.build(a), t1.build(even), t2.build(odd);
  ll m;
  cin >> m;
  while (m--) {
    ll type, i, j;
    cin >> type >> i >> j;
    i--;
    if (type) {
      cout << t.get(i, j) + (i + 1 & 1 ? t2.get(i, j) : t1.get(i, j)) << '\n';
    } else {
      t.set(i, j);
      if (i & 1)
        t2.set(i, j);
      else
        t1.set(i, j);
    }
  }
}
