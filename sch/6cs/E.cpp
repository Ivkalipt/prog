// #pragma gcc optimize ("o3,unroll-loops")
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

bool ifis(string & s, ll i) {
  string p = "";
  p += s[i - 3]; p += s[i - 2]; p += s[i - 1]; p += s[i];
  return (p == "<-<<" || p == ">>->");
}
int main() {
  fastio;
  string s;
  cin >> s;
  ll n = s.size();
  if(n < 4) cout << 0 << '\n', exit(0); 
  vll dp(max(n, 8LL), 0);
  dp[3] = (n > 3 ? ifis(s, 3) : 0);
  dp[4] = (n > 4 ? ifis(s, 4) : 0);
  dp[5] = (n > 5 ? ifis(s, 5) : 0);
  dp[6] = (n > 6 ? ifis(s, 6) : 0);
  dp[7] = (n > 7 ? ifis(s, 7) : 0) + max({dp[3], dp[2], dp[1], dp[0]});
  for(ll i = 8; i < s.size(); i++) {
    dp[i] = ifis(s, i) + max({dp[i - 4], dp[i - 5], dp[i - 6], dp[i - 7]});
  }
  cout << max({dp[n - 1], dp[n - 2], dp[n - 3], dp[n - 4]}) << '\n';


  /*for(ll & c : cntr) cout << c << ' ';
  cout << '\n';*/
}
