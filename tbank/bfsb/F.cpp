// #pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

constexpr ll INF = 1e16;
constexpr ll MAXN = 1e3 + 10;

vpll maybe = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
ll n;

struct step {
  ll x, y;
};

void bfs(ll x, ll y, vvll & d) {
  d[x][y] = 0;
  queue<pll> q;
  q.push({x, y});
  while (!q.empty()) {
    auto [x1, y1] = q.front();
    q.pop();
    for (pll a : maybe) {
      ll x2 = x1 + a.F, y2 = y1 + a.S;
      if (0 >= x2 || x2 > n || 0 >= y2 || y2 > n || d[x2][y2] != -1) continue;
      d[x2][y2] = d[x1][y1] + 1;
      q.push({x2, y2});
    }
  } 
}

int main() {
  ll x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  vector d1(MAXN, vector(MAXN, -1LL)), d2(MAXN, vector(MAXN, -1LL));
  bfs(x1, y1, d1), bfs(x2, y2, d2);
  ll mn = INF;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (d1[i][j] == d2[i][j] && d1[i][j] != -1 && d1[i][j] < mn) mn = d1[i][j];
      // cout << d1[i][j] << ' ';
    }
    // cout << '\n';
  }
  cout << (mn == INF ? -1 : mn) << '\n'; 
}


