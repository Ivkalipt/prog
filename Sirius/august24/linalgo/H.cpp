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

int main() {
  ll n;
  cin >> n;
  vll a(n);
  for (ll &c : a)
    cin >> c;
  sort(all(a));
  ll l = 0, r = 1, max_size = 1;
  while (r != n) {
    while (abs(a[r] - a[l]) > 5)
      l++;
    r++;
    if (r - l > max_size)
      max_size = r - l;
  }
  cout << max_size << '\n';
}
