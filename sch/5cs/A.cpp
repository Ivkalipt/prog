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

ll sum(ll x) {
  ll s = 0;
  for(char c : to_string(x)) {
    s += c - '0';
  }
  return s;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ll t;
  vll a;
  while(cin >> t) {
    a.push_back(t);
  }
  sort(all(a), [](ll x, ll y) {
    return sum(x) < sum(y);
  });
  for(ll c : a) cout << c << ' ';
}
