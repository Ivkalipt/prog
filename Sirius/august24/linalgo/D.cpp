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

#define MOD (1ULL << 32)

void solve() {
  ll n;
  cin >> n;
  vll a(n);
  for (ll &c : a)
    cin >> c;
  for (ll i = 0; i < n / 2; i++) {
    cout << a[i] << ' ' << a[n - i - 1] << ' ';
  }
  if (n & 1)
    cout << a[n / 2];
  cout << '\n';
}

int main() {
  fastio;
  ll t;
  cin >> t;
  while (t--)
    solve();
}
