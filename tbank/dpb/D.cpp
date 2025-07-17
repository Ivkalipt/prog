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

const ll inf = 1e9 + 7;

int main() {
  ll n, m;
  cin >> n;
  vll a(n);
  for(ll & c : a) cin >> c;
  cin >> m;
  vll b(m);
  for(ll & c : b) cin >> c;
  vvll dp(n + 1, vll(m + 1, 0));
  for(ll i = 1; i <= n; i++)
    for(ll j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      if(a[i - 1] == b[j - 1])
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
    }
  cout << dp[n][m] << '\n';
}
