#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll maxn = 4e5 + 5, k = 911382629, MOD = 1e9 + 7;

ll power[maxn];

void init_power() {
  power[0] = 1;
  for (ll i = 1; i < maxn; i++) {
    power[i] = (power[i - 1] * k) % MOD;
  }
}

void init_hash(const vector<ll> &s, vector<ll> &h) {
  h[0] = 0;
  for (ll i = 0; i < s.size(); i++) {
    h[i + 1] = (h[i] * k + s[i]) % MOD;
  }
}

ll get_hash(ll l, ll r, const vector<ll> &h) {
  return (h[r + 1] - h[l] * power[r - l + 1] % MOD + MOD) % MOD;
}

int main() {
  fastio;
  init_power();

  ll n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  if (n == 1) {
    ll d = t[0] - s[0];
    cout << "Success\n";
    cout << "0 " << d << '\n';
    return 0;
  }

  s += s;
  vector<ll> ds(2 * n - 1), dt(n - 1);
  for (ll i = 0; i < 2 * n - 1; i++) {
    ds[i] = s[i + 1] - s[i];
  }
  for (ll i = 0; i < n - 1; i++) {
    dt[i] = t[i + 1] - t[i];
  }

  vector<ll> hs(2 * n), ht(n);
  init_hash(ds, hs);
  init_hash(dt, ht);

  ll target_hash = get_hash(0, n - 2, ht);
  bool found = false;
  ll shift = 0;

  for (ll i = 0; i <= n; i++) {
    if (get_hash(i, i + n - 2, hs) == target_hash) {
      found = true;
      shift = i;
      break;
    }
  }

  if (!found) {
    cout << "Impossible\n";
    return 0;
  }

  ll d = t[0] - s[shift];

  cout << "Success\n";
  cout << (n - shift) % n << ' ' << d << '\n';

  return 0;
}
