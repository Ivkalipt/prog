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

void solve() {
  ll n, m;
  cin >> n;
  vll a(n);
  for (ll &c : a)
    cin >> c;
  cin >> m;
  vll b(m);
  for (ll &c : b)
    cin >> c;
  ll i = 0, j = 0, min_diff = INF, min_a, min_b;
  while (i < n && j < m) {
    if (abs(a[i] - b[j]) < min_diff)
      min_diff = abs(a[i] - b[j]), min_a = a[i], min_b = b[j];
    if (a[i] > b[j])
      j++;
    else
      i++;
  }
  /*while (i < n) {
    if (abs(a[i] - b[j]) < min_diff)
      min_diff = abs(a[i] - b[j]), min_a = a[i], min_b = b[j];
    i++;
  }
  while (j < n) {
    if (abs(a[i] - b[j]) < min_diff)
      min_diff = abs(a[i] - b[j]), min_a = a[i], min_b = b[j];
    j++;
  }*/
  cout << min_a << ' ' << min_b << '\n';
}

int main() {
  fastio;
  /*ll t;
  cin >> t;
  while (t--)*/
  solve();
}
