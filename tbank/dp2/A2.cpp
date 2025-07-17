#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll int
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define mkpair make_pair

using namespace std;

const ll inf = 1e9 + 7;

bool f = 0;

void path(vll a, vector<vpll>& p, ll i, ll j) {
  if(i == 0 && j == 0) return;
  if(p[i][j] == mkpair(i - 1, j - 1)) {
    path(a, p, i - 1, j - 1);
    cout << a[i - 1] << ' ';
    f = 1;
  }
  else path(a, p, p[i][j].F, p[i][j].S);
}

int main() {
  ll n, m;
  cin >> n;
  vll a(n);
  for(ll & c : a) cin >> c;
  cin >> m;
  vll b(m);
 vector<vpll> p(n + 1, vpll(m + 1, mkpair(0, 0)));
  for(ll & c : b) cin >> c;
  vvll dp(n + 1, vll(m + 1, 0));
  for(ll i = 1; i <= n; i++)
    for(ll j = 1; j <= m; j++) {
      if(dp[i - 1][j] > dp[i][j - 1]) {
        dp[i][j] = dp[i - 1][j];
        p[i][j] = {i - 1, j};
      }
      else {
        dp[i][j] = dp[i][j - 1];
        p[i][j] = {i, j - 1};
      }
      if(a[i - 1] == b[j - 1]) {
        if(dp[i][j] < dp[i - 1][j - 1] + 1) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          p[i][j] = {i - 1, j - 1};
        }
      }
    }
  cout << dp[n][m] << '\n';
  path(a, p, n, m);
  cout << (f ? "\n" : "");
  
}
