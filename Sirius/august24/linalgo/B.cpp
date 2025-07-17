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

#define MOD (1ULL << 32)

int main() {
  unsigned long long n, a0, k, s;
  cin >> n >> a0 >> k >> s;
  unsigned long long ai = a0;
  ll max1 = a0, max2 = a0;
  for (ll i = 1; i < n; i++) {
    ai = (ai * k + s) % MOD;
    if (ai > max1)
      max2 = max1, max1 = ai;
  }
  cout << max1 << ' ' << max2 << '\n';
}
