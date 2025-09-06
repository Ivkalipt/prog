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
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  vll sky(n), gnd(n);
  for (ll & x : sky) cin >> x;
  for (ll & x : gnd) cin >> x;
  ll res = 0;
  ll pow10 = 1;
  for (ll i = n - 1; i > -1; i--) {
    res += (sky[i] * 5 + gnd[i]) * pow10;
    pow10 *= 10;
  }
  cout << res << '\n';
}
