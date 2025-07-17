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
  ll n, cnt = 0;
  cin >> n;
  bool flag = 0;
  for(ll i = 0; i < n; i++) {
    if(!flag) {
      for(ll j = 0; j < n; j++) 
        cnt++, cout << cnt << ' ';
      flag = 1;
      cout << '\n';
    }
    else {
      cnt += n;
      for(ll j = 0; j < n; j++) 
        cout << cnt << ' ', cnt--;
      cnt += n;
      flag = 0;
      cout << '\n';
    }
  }
}
