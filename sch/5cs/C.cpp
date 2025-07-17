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
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ll mini = 1e9 + 7;
  ll maxi = -mini;
  string t;
  ll n;
  vll a;
  getline(cin, t);
  ll cnt = 0;
  for(char c : t)
    if(c == ' ')
      cnt++;
  stringstream p(t);
  for(ll i = 0; i <= cnt; i++) {
    p >> n;
    if(n % 2 == 0) {
      if(n > maxi) {
        maxi = n;
      }
      if(n < mini) {
        mini = n;
      }
    }
  }
  cout << (maxi != -1e9 - 7 ? to_string(maxi) : "") << ' ' << (mini != 1e9 + 7 ? to_string(mini) : "") << '\n';
    
 
}
