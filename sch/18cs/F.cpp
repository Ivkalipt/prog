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

vector<bool> sieve(ll n) {
  vector<bool> isPrime(n + 1, true);
  for (ll i = 2; i <= n; i++) {
    if (isPrime[i])
      for (ll j = 2 * i; j <= n; j += i) {
        isPrime[j] = false;
      }
  }
  isPrime[1] = false;
  return isPrime;
}

int main() {
  ll a, b;
  cin >> a >> b;
  vector isPrime = sieve(b);
  ll sum = 0, cnt = 0;
  for (ll i = a; i <= b; i++) {
    if (isPrime[i]) {
      cnt++;
      sum += i;
    }
  }
  cout << sum << ' ' << cnt << '\n';
}
