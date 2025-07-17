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

struct syms {
  ll i, j, x;
};

int main() {
  ll n, symbol = 0;
  cin >> n;
  vvll a(n, vll(n, 0)), b(n, vll(n, 0));
  for(ll i = 0; i < n; i++) {
    for(ll & c : a[i]) {
      cin >> c;
    }
  }
  b = a;
  vector<syms> sym;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      if(a[i][j]) sym.push_back({i, j, a[i][j]});
    }
  }
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      if(a[i][j]) continue;
      // unordered_set<ll> dist;
      bool f = 0;
      ll mini = inf;
      for(ll k = 0; k < (ll)sym.size(); k++) {
        ll d = abs(sym[k].i - i) + abs(sym[k].j - j);
        if(d == mini) {
          f = 1;
        }
        if(d < mini) {
          mini = d;
          symbol = sym[k].x;
          f = 0;
        }
        // dist.insert(mini);
      }
      if(!f) b[i][j] = symbol;
    }
  }
  //for(auto s : sym) cout << s.i << ' ' << s.j << ' ' << s.x << '\n';
  //cout << '\n';
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cout << b[i][j] << ' ';
    }
    cout << '\n';
  }
  
}
