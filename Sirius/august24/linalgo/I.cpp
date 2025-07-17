#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
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

#define INF 1e18

int main() {
  ll n, k;
  cin >> n >> k;
  vll a(n);
  for (ll &c : a)
    cin >> c;
  ll l = 0, r = 0, min_len = INF, min_l, min_r;
  while (r != n) {
    k -= a[r];
    while ((k < 0 || a[l] == 0) && l < r)
      k += a[l], l++;
    r++;
    if (r - l < min_len && k == 0) {
      min_len = r - l, min_l = l, min_r = r;
      // cout << min_len << '\n';
    }
    // cout << l << ' ' << r << ' ' << k << '\n';
  }
  if (min_len == INF)
    cout << -1 << '\n';
  else
    cout << min_l + 1 << ' ' << min_r << '\n';
}
