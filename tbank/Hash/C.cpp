#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll MOD = 1e9 + 9, maxn = 1e6 + 5;
ll straight_h[maxn], reverse_h[maxn], power[maxn];
ll n, k;

void init_hash(vll &s) {
  power[0] = 1;
  for (ll i = 0; i < n; i++) {
    power[i + 1] = power[i] * k % MOD;
    straight_h[i + 1] = (straight_h[i] * k + s[i]) % MOD;
  }
  for (ll i = n - 1; i > -1; i--) {
    reverse_h[i] = (reverse_h[i + 1] * k + s[i]) % MOD;
  }
}

ll get_straight_hash(ll l, ll r) {
  return ((straight_h[r + 1] - straight_h[l] * power[r - l + 1] % MOD + MOD) %
          MOD);
}

ll get_reverse_hash(ll l, ll r) {
  return ((reverse_h[l] - reverse_h[r + 1] * power[r - l + 1] % MOD + MOD) %
          MOD);
}

inline bool check(ll l, ll r) {
  // cout << get_straight_hash(l2, r2) << ' ' << get_reverse_hash(l1, r1) <<
  // '\n';
  return get_straight_hash(l, r) == get_reverse_hash(l, r);
}

int main() {
  ll m;
  cin >> n >> m;
  k = m + 1;
  // assert(n > 1);
  vll a(n), ans = {n};
  ll cnt = 0;
  for (ll &c : a)
    cin >> c;
  init_hash(a);
  for (ll k = 0; k < n; k += 2) {
    if (check(0, k - 1))
      ans.push_back(n - 1 - k);
    cout << check(0, k - 1) << ' ' << 0 << ' ' << k - 1 << '\n';
  }
  reverse(all(ans));
  for (ll c : ans)
    cout << c << ' ';
}
