#include <endian.h>
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

int main() {
  ll b, k, x, y;
  cin >> b >> k >> x >> y;
  vpll d(x + 1), p(y + 1);
  vll pref_d(x + 1), pref_p(y + 1);
  for (ll i = 1; i <= x; i++) cin >> d[i].F, d[i].S = i; 
  for (ll i = 1; i <= y; i++) cin >> p[i].F, p[i].S = i;
  sort(d.begin() + 1, d.end(), [&] (const pll a, const pll b) {
    return a.F > b.F;
  });
  sort(p.begin() + 1, p.end(), [&] (const pll a, const pll b) {
    return a.F > b.F;
  });
  for (ll i = 1; i <= x; i++) pref_d[i] = pref_d[i - 1] + d[i].F;
  for (ll i = 1; i <= y; i++) pref_p[i] = pref_p[i - 1] + p[i].F;
  ld max_power = -INF;
  ll bp = 0, bd = 0;
  for (ll i = 0; i <= min(k, x); i++) {
    ld power = (b + pref_d[i]) * (pref_p[min(k - i, y)] + 100) / (ld)100;
    if (power > max_power) {
      max_power = power;
      bp = i;
      bd = min(k - i, y);
    }
  }
  /*cout << max_power << '\n';
  for (ll x : pref_d) cout << x << ' ';
  cout << '\n';
  for (ll x : pref_p) cout << x << ' ';
  cout << '\n';*/
  cout << bp << ' ' << bd << '\n';
  for (ll i = 1; i <= bp; i++) cout << d[i].S << ' ';
  cout << '\n';
  for (ll i = 1; i <= bd; i++) cout << p[i].S << ' ';
  cout << '\n';

}
