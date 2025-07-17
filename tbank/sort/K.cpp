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
  ll n, b, t;
  cin >> b >> n;
  vll a;
  for(ll i = 0; i < n; i++) {
      cin >> t;
      if(t >= b) a.push_back(t);
  }
  n = a.size();
  if(n == 0) cout << 0 << '\n', exit(0);
  sort(all(a));
  vll dp(n, 1);
  dp[0] = 1;
  for(ll i = 1; i < n; i++)
    for(ll j = 0; j < i; j++)
      if(a[j] + 3 <= a[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
      }
  ll maxi = 1;
  for(ll i = 0; i < n; i++) {
    if(dp[i] > dp[maxi]) {
      maxi = i;
    }
  }
  cout << dp[maxi] << '\n';
}
