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
  string s1, s2;
  cin >> s1 >> s2;
  ll n1 = s1.size(), n2 = s2.size();
  vector<char> a(all(s1)), b(all(s2)), ans;
  ll i = 0, j = 0;
  while(i != n1 - 1 && j != n2 - 1) {
    if(i == n1) ans.push_back(a[j++]);
    else if(j == n2) ans.push_back(b[i++]);
    else {
      if(a[i] > b[j]) ans.push_back(a[i++]);
      else ans.push_back(b[j++]);
    }
  }
  for(char c : ans) cout << c;

  cout << '\n';

}
