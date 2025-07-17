#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i <= (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18, MOD = 1e9 + 7;

ll f(ll x) {
  ll full = x / 9 * 45;
  ll module = (x % 9 + 1) * (x % 9) / 2;
  return full + module;
}

int main() {
  ll q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << '\n';
  }
}
