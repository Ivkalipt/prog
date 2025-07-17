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
  string a;
  cin >> a;
  for(ll i = 0; i < (a.size() >> 1); i++) {
    if(a[i] != a[a.size() - i - 1]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
