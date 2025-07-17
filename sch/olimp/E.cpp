#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
  ll n, m;
  cin >> n >> m;
  vvll dp(n + 1, vll(m + 1, 0));
  dp[1][1] = 1;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= m; j++) {
      if(i != 1 || j != 1) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }
  }
  cout << dp[n][m] << '\n';

}
