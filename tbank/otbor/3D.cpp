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
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr ll MAX_CORD = 5e5;

signed main() {
  fastio;
  ll t, s;
  cin >> t >> s;

  ll max_time = 0;
  while (1 == 1) {
    ll pos = s + ((max_time * (max_time + 1)) >> 1);
    if (pos > MAX_CORD) {
      max_time--;
      break;
    }
    max_time++;
  }

  vll kotty_pos;
  kotty_pos.push_back(t);
  vector used(MAX_CORD + 1, -1); 

  for (ll i = 0; i <= max_time; i++) {
    ll cur_kissy_cord = s + i * (i + 1) / 2;
    if (cur_kissy_cord > MAX_CORD) break;

    for (ll x : kotty_pos) {
      if (x == cur_kissy_cord) {
        cout << i << endl;
        return 0;
      }
    }

    if (t == max_time)
      break;

    vll new_kotty_pos;
    for (ll x : kotty_pos) {
      for (ll y : {x + 1, x - 1, 2 * x}) {
        if (y < 0 || y > MAX_CORD) continue;
        if (used[y] != i + 1) {
          used[y] = i + 1;
          new_kotty_pos.push_back(y);
        }
      }
    }
    kotty_pos = vector(all(new_kotty_pos));
  }

  cout << -1 << endl;
  return 0;
}
