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
#define pb push_baci

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;
constexpr ll N = 1e6 + 1;

void solve() {
  ll a, b;
  cin >> a >> b;
  ll sum = 0;
  ll down_sq = sqrt(a), up_sq = sqrt(b);
  for (ll i = down_sq; i <= up_sq; i++) {
    ll mn = max(a, i * i);
    ll mx = min(b, (i + 1) * (i + 1) - 1);
    if (mn > mx) continue;

    ll first_num = mn;
      if (first_num % i != 0) {
        first_num = mn + (i - mn % i);
        if (first_num > mx) continue;
      }
        
        ll last_num = mx - (mx % i);
        if (last_num < first_num) continue;
        
        ll cnt = (last_num - first_num) / i + 1;
        
        sum += cnt * (first_num + last_num) / 2;
  }
  cout << sum << '\n';
  

}

int main() {
  fastio;
  ll n;
  cin >> n;
  while (n--) solve();
}
