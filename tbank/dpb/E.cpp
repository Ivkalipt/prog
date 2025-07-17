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
  ll n, w;
  cin >> n >> w;
  vector<vector<bool>> dp(n + 1, vector<bool>(w, 0));
  // j - масса рассматривая i первых
  for(ll i = 0; i < n; i++) {
    dp[i][0] = true;
  }
  for(ll i = 1; i < n; i++) {
    for(ll j = 0; j < w; j++) {
      dp[i][j] = dp[i - 1][j];
      if(j >= a[i]) dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][j - a[i]];
    }
  }


}
