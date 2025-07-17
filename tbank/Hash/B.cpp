#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll MOD = 1e9 + 7, k = 26, maxn = 1e5 + 5;
ll straight_h[maxn], reverse_h[maxn], power[maxn];
ll n;

void init_hash(string &s) {
  power[0] = 1;
  n = s.size();
  for (ll i = 0; i < n; i++) {
    power[i + 1] = power[i] * k % MOD;
    ll c = s[i] - 'a' + 1;
    straight_h[i + 1] = (straight_h[i] * k + c) % MOD;
  }
  for (ll i = n - 1; i > -1; i--) {
    ll c = s[i] - 'a' + 1;
    reverse_h[i] = (reverse_h[i + 1] * k + c) % MOD;
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
  return get_straight_hash(l, r) == get_reverse_hash(l, r);
}

int main() {
  fastio;
  string s;
  cin >> s;
  n = s.size();
  init_hash(s);
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    ll l = 0, r = min(i, n - i - 1);
    ll mx = 0;
    while (l <= r) {
      ll m = (l + r) >> 1;
      if (check(i - m, i + m))
        mx = l, l = m + 1;
      else
        r = m - 1;
    }
    cnt += l;
    // cout << mx + 1 << ' ';
  }
  // cout << '\n';

  for (ll i = 1; i < n; i++) {
    if (s[i] != s[i - 1])
      continue;
    ll l = 0, r = min(i - 1, n - i - 1);
    ll mx = 0;
    while (l <= r) {
      ll m = (l + r) >> 1;
      if (check(i - 1 - m, i + m))
        mx = l, l = m + 1;
      else
        r = m - 1;
    }
    cnt += l;
    // cout << mx + 1 << ' ';
  }
  cout << cnt << '\n';
}
