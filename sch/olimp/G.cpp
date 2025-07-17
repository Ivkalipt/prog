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
  ll n, k, cnt = 0;
  cin >> n >> k;
  vll dp(n);
  dp[0] = 1;
  dp[1] = 1;
  for(ll i = 2; i < n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
    if(dp[i] % k == 0) cnt++;
  }
  cout << cnt << '\n';

  

}
