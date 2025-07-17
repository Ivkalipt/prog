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
  fastio;
  ll n, q, maxi = -1;
  cin >> n;
  vll a(n);
  for(ll & c : a) cin >> c;
  cin >> q;
  vll x(q);
  for(ll & c : x) cin >> c;
  vll cnt(6e5 + 2, 0);
  for(ll c : a) {
    cnt[c]++;
    if(c > maxi) {
      maxi = c;
    }
  }
  vll pref(6e5 + 2, 0);
  for(ll i = 1; i <= 6e5 + 2; i++) {
    pref[i] = pref[i - 1] + cnt[i];
  }
  ll j1;
  bool f = 0;
  for(ll i = 0; i < q; i++) {
    ll maxi2;
    for(ll j = x[i] - 1; j <= 6e5 + 2; j += x[i]) {
      if(j == x[i] - 1) {
        maxi2 = pref[x[i] - 1];
        continue;
      }
      if(pref[j] - pref[j - x[i]] > maxi2) {
        maxi2 = pref[j] - pref[j - x[i]];
      }
      if(j == maxi) f = 1;
      else {
        f = 0;
        j1 = j;
      }
    }
    cout << maxi2 << ' ';
    /*else {
      j1 = min(x[i] + j1, (ll)3e5);
      if(maxi < pref[j1] - pref[j1 - x[i]]) {
        maxi = pref[j1] - pref[j1 - x[i]];
      }
      cout << maxi << '\n';
    }*/
  }
  
}
