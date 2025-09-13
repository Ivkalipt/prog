#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

struct Counter {
  vll d;
  ll n;

  u64 countUpTo(u64 N) {
    if (N == 0) return 0;
    d = toDigits(N);
    n = (ll)d.size();
    u64 total = 0;

    ll Smax = 9 * n;

    for (ll S = 1; S <= Smax; ++S) {
      ll posDim = n + 1;
      ll tightDim = 2;
      ll sumDim = S + 1;
      ll prodDim = S;
      ll startedDim = 2;
      size_t TOT = (size_t)posDim * tightDim * sumDim * prodDim * startedDim;
      vector<long long> memo(TOT, -1);

      auto idx = [&](ll pos, ll tight, ll sum, ll prod, ll started)->size_t {
        size_t x = pos;
        x = x * 2 + tight;
        x = x * (S + 1) + sum;
        x = x * S + prod;
        x = x * 2 + started;
        return x;
      };

      function<u64(ll,ll,ll,ll,ll)> dfs = [&](ll pos, ll tight, ll sum, ll prod, ll started)->u64 {
        ll rem = n - pos;
        if (sum > S) return 0;
        if (sum + 9 * rem < S) return 0;

        if (pos == n) {
          return (started && sum == S && prod % S == 0) ? 1ULL : 0ULL;
        }

        size_t id = idx(pos, tight, sum, prod, started);
        long long &cached = memo[id];
        if (cached != -1) return (u64)cached;

        ll lim = tight ? d[pos] : 9;
        u64 res = 0;

        for (ll dig = 0; dig <= lim; ++dig) {
          ll ntight = tight && (dig == lim);
          if (!started) {
            if (dig == 0) {
              res += dfs(pos + 1, ntight, 0, 1 % S, 0);
            } else {
              ll nsum = dig;
              if (nsum <= S) {
                ll nprod = dig % S;
                res += dfs(pos + 1, ntight, nsum, nprod, 1);
              }
            }
          } else {
            ll nsum = sum + dig;
            if (nsum > S) continue;
            ll nprod = (dig == 0) ? 0 : (ll)((1LL * prod * dig) % S);
            res += dfs(pos + 1, ntight, nsum, nprod, 1);
          }
        }

        cached = (long long)res;
        return res;
      };

      total += dfs(0, 1, 0, 1 % S, 0);
    }

    return total;
  }

  static vll toDigits(u64 N) {
    string s = to_string(N);
    vll a(s.size());
    for (size_t i = 0; i < s.size(); ++i) a[i] = s[i] - '0';
    return a;
  }
};

signed main() {
  fastio;
  u64 L, R;
  cin >> L >> R;

  Counter C;
  auto ans = C.countUpTo(R) - C.countUpTo(L - 1);
  cout << ans << "\n";
  return 0;
}
