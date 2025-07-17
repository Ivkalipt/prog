#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
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
  ll x1, y1, x, y, k, l, ans = 0;
  cin >> x1 >> y1 >> k >> l;
  x = min(x1, y1);
  y = max(x1, y1);
  if(2 * l > k) {
    cout << 0 << '\n';
    return 0;
  }
  ll s = (x <= 0 ? (ll)(x / k) * k : (ll)ceill((ld)y / k));
  ll f = (y <= 0 ? ceill((ld)y / k) : (ll)(y / k) * k);
  if(f < x || s > y) {
    cout << ceill((ld)abs(y - f) / (2 * l)) << '\n';
    return 0;
  }
  if(abs(x - s) > l) {
    x += l;
    ans += ceill((ld)abs(x - s) / (2 * l));
  }
  if(abs(y - f) > l) {
    y -= l;
    ans += ceill((ld)abs(y - f) / (2 * l));
  }
  //ans += ceill((ld)abs(y - f) / (2 * l)) + ceill((ld)abs(x - s) / (2 * l));
  // cout << ans << '\n';
  if(s + 2 * l < f) {
    ll t1 = ceill((ld)(k - 2 * l) / (2 * l));
    ll t2 = (abs(f - s) / k) * t1;
    ans += t2;
    // cout << t1 << '\n';
  }
  // cout << s << ' ' << f << ' ' << x << ' ' << y << '\n';
  cout << ans << '\n';



}
