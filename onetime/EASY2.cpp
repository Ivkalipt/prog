#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

ll solve(ll X) {
  X += 3;
  ll cnt = 0;
  for (ll i = 2; i * i <= X; i++) {
    if (X % i == 0) {
      if (i * i == X)
        cnt++;
      else
        cnt += 2;
    }
  }
  return cnt;
}

int main() {
  ll t;
  cin >> t;

  while (t--) {
    ll X;
    cin >> X;
    cout << solve(X) << endl;
  }

  return 0;
}
