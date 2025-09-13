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
  ll x;
  cin >> x;
  string min_num_str = "0";
  ll ss = 0, min_num = INF;
  for (ll i = 2; i <= 36; i++) {
    for (ll nsym = 1; nsym < i; nsym++) {
      char sym;
      if (nsym < 10) sym = nsym + '0';
      else sym = nsym - 10 + 'A';
      ll len_num_sym = 1, num_10 = nsym * 1, pow_i = i;
      while (num_10 < x) {
        len_num_sym++;
        num_10 += pow_i * nsym;
        pow_i *= i;
      }
      if (num_10 < min_num) {
        min_num_str = string(len_num_sym, sym);
        ss = i;
        min_num = num_10;
      }
   }
  }
  cout << ss << ' ' << min_num_str << '\n';
}
