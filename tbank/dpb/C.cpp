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
  ll n;
  cin >> n;
  vll a(n), dp(n, 1), p(n, -1);
  for(ll & c : a) cin >> c;
  dp[0] = 1;
  for(ll i = 1; i < n; i++)
    for(ll j = 0; j < i; j++)
      if(a[j] < a[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        p[i] = j;
      }
  ll maxi = 1;
  for(ll i = 0; i < n; i++) {
    if(dp[i] > dp[maxi]) {
      maxi = i;
    }
  }
  vll way(dp[maxi]);
  ll ind = maxi;
  ll i = 0;
  while(ind != -1) {
    way[i] = a[ind];
    ind = p[ind];
    i++;
  }
  cout << dp[maxi] << '\n';
  for(ll j = dp[maxi] - 1; j > -1; j--) cout << way[j] << ' ';
  cout << '\n';
}
