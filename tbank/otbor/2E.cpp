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

int main() {
  ll n, k;
  cin >> n >> k;
  vll a(n + 1), pref(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = a[i] + pref[i - 1]; 
  }
  set<ll> pref_ok = {0};
  ll cnt = 0, curi = 1;
  for (ll i = 1; i <= n; i++) {
    if (pref_ok.count(pref[i] - pref[curi - 1] - k)) {
      cnt++;
      pref_ok.clear();
      pref_ok.insert(0);
      curi = i;
    }
    pref_ok.insert(pref[i] - pref[curi - 1]);
  }
  cout << cnt << '\n';


}
