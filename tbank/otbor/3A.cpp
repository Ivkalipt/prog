#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

struct Point {
  ld x, y;
};

struct Segment {
  Point s, f;
};

inline ld getArea(const Point & a, const Point & b, const Point & c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool onSegment(const Point & a, const Point & b, const Point & c) {
  return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
         min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

inline bool intersect(ld x1, ld x2, ld x3, ld x4) {
  if (x1 > x2) swap(x1, x2);
  if (x3 > x4) swap(x3, x4);
  return max(x1, x3) <= min(x2, x4);
}

bool isIntersect(Segment seg1, Segment seg2) {
  Point a = seg1.s, b = seg1.f;
  Point c = seg2.s, d = seg2.f;
  
  if (!intersect(a.x, b.x, c.x, d.x) || !intersect(a.y, b.y, c.y, d.y)) {
    return false;
  }
  
  ld o1 = getArea(a, b, c);
  ld o2 = getArea(a, b, d);
  ld o3 = getArea(c, d, a);
  ld o4 = getArea(c, d, b);
  
  if (o1 * o2 < 0 && o3 * o4 < 0) {
    return true;
  }
  
  return false;
}

int main() {
  ll n;
  cin >> n;
  vector<Segment> segs(n);
  ll ans = 1;
  for (ll i = 0; i < n; i++) {
    Segment s;
    cin >> s.s.x >> s.s.y >> s.f.x >> s.f.y;
    segs[i] = s;
    ll cnt = 0;
    for (ll j = 0; j < i; j++) {
      if (isIntersect(segs[i], segs[j]))
        cnt++;
    }
    ans += cnt + 1;
    cout << ans << '\n';
  }
}
