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
  ll n, m, maxi = 0, i1 = 0, j1 = 0;
  cin >> n >> m;
  vvll a(n + 1, vll(m + 1, 0)), dp(n + 1, vll(m + 1, 0));
  for(ll i = 1; i <= n; i++)
    for(ll j = 1; j <= m; j++) 
      cin >> a[i][j];
  for(ll i = 1; i <= n; i++)
    for(ll j = 1; j <= m; j++) {
      if(!a[i][j]) dp[i][j] = 0;
      else dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
      if(dp[i][j] > maxi) maxi = dp[i][j], i1 = i, j1 = j;
    }
  cout << maxi << '\n' << i1 - maxi + 1 << ' ' << j1 - maxi + 1 << '\n';

  

}
