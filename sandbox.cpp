#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e18;



void solve() {
  ll n; cin >> n;
  vll a(n);
  for (ll & c : a) cin >> c;
  ll x = 1;
  for (ll i = n - 2; i > -1; i--) {
    if (a[i + 1] % a[i] != 0) {
      a[i] /= x;
      x *= a[i] / __gcd(a[i], a[i + 1]);
    }
  }
  cout << x << '\n';
}

int main() {
  ll t;
  cin >> t;
  while (t--) solve();
}
