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
  ll i = 0, j = 0;
  string s1, s2;
  cin >> s1 >> s2;
  vector<char> a;
  while(i != s1.size() || j != s2.size()) {
    //cout << '!';
    if(i == s1.size()) {
      a.push_back(s2[j++]);
    }
    else if(j == s2.size()) {
      a.push_back(s1[i++]);
    }
    else {
      if(s1[i] > s2[j]) {
        a.push_back(s1[i++]);
      }
      else if(s1[i] < s2[j]) {
        a.push_back(s2[j++]);
      }
      else {
        ll i1 = i, j1 = j;
        ll f1 = 1;
        while(i1 != s1.size() && j1 != s2.size()) {
          if(s1[i1] > s2[j1]) {
            f1 = 2;
            break;
          }
          else if(s1[i1] < s2[j1]) {
            f1 = 1;
            break;
          }
          i1++, j1++;
        }
        if(f1 == 2) {
          a.push_back(s1[i++]);
        }
        else {
          a.push_back(s2[j++]);
        }
      }
    }
  }
  string b(all(a));
  cout << b << '\n';
}
