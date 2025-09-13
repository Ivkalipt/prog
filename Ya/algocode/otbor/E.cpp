#include <strings.h>
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
  ll n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vll pa(n + 1), pc(n + 1), indexes;
  for (ll i = 1; i <= n; i++) {
    pa[i] = pa[i - 1] + (s[i - 1] == 'a' ? 1 : 0);
    pc[i] = pc[i - 1] + (s[i - 1] == 'c' ? 1 : 0);
    s[i - 1] == 'b' ? indexes.push_back(i) : (void)0;
    // cout << pc[i] << ' ';
  }
  // cout << '\n';

  ll sz_idx = sz(indexes);

  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll lx = 0, rx = sz_idx;
    while (rx - lx > 1) {
      ll mid = (lx + rx) >> 1;
      if (l <= indexes[mid]) rx = mid;
      else lx = mid;
      // cout << lx << ' ' << rx << '\n';
    }
    ll l_idx = rx;
    lx = -1, rx = sz_idx;
    while (rx - lx > 1) {
      ll mid = (lx + rx) >> 1;
      if (r >= indexes[mid]) lx = mid;
      else rx = mid;
      // cout << lx << ' ' << rx << '\n';
    }
    ll r_idx = lx;
    ll mx_k = min(pa[r] - pa[l - 1], pc[r] - pc[l - 1]);
    lx = 0, rx = mx_k;
    ll low_k = 0, high_k = mx_k;
    while (low_k <= high_k) {
      ll mid_k = (low_k + high_k) >> 1;

      bool found = false;

      ll L0 = n + 1;
      ll low = 0, high = n;
      while (low <= high) {
        ll mid = (low + high) >> 1;
        if (pa[mid] >= pa[l - 1] + mid_k) {
          L0 = mid;
          high = mid - 1;
        } else
          low = mid + 1;
      }

      ll R0 = -1;
      low = 0, high = n;
      while (low <= high) {
        ll mid = (low + high) >> 1;
        if (pc[mid] <= pc[r] - mid_k) {
          R0 = mid;
          low = mid + 1;
        } else
          high = mid - 1;
      }

      ll lb = max(l, L0 + 1);
      ll rb = min(r, R0);

      if (lb <= rb) {
        auto it_l = lower_bound(all(indexes), lb);
        auto it_r = upper_bound(all(indexes), rb);
        if (it_l < it_r) found = true;
      }
      (found ? low_k = mid_k + 1 : high_k = mid_k - 1);
    }

    cout << max(0LL, 2 * high_k + 1) << '\n';    
  }


}
