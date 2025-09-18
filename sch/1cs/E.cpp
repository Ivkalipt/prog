// #pragma GCC optimize("Ofast,unroll-loops")
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

ll flags[101];

int main() {
  ll n, k;
  cin >> n >> k;
  vector<vector<string>> Comps(n);
  while (k--) {
    ll m;
    char sym;
    cin >> m >> sym;
    m--;
    if (sym == 8) {
      if (!flags[m]) {
        Comps[m].pop_back();
        flags[m]--;
      }
    }

    else if (sym == 13) {
      flags[m] = 0;
      Comps[m].push_back("//");
    }
    
    else {
      flags[m]++;
      Comps[m].push_back(to_string(sym));
    }
  }
  for (vector<string> c : Comps) {
    for (string sym : c) {
      cout << sym;
    }
    cout << '\n';
  }
}
