
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

ll inf = 1e9 + 7;

int main() {
  ll n, t;
  cin >> n >> t;
  vvll dp(n, vll(26, 0));
  dp[0][t] = 1;
  for(ll i = 1; i < n; i++) {
    cin >> t;
		for (ll j = 0; j < 26; ++j) {
			if (j >= t) dp[i][j] += dp[i - 1][j - t] % inf;
			if (t && j + t < 26) dp[i][j] += dp[i - 1][j + t] % inf;
		}
  }
  ll s = 0;
  for(ll c : dp[n - 1]) s += c % inf;
  cout << s % inf << '\n';


}
