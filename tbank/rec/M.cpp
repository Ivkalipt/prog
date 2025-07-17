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

ll cnt = 0;

void rec(ll pos, ll n, ll k, vll & col, vector<vector<bool>> & wires) {
  if(pos == n + 1) {
    cnt++;
    return;
  }
  for(ll i = 1; i <= k; i++) {
    bool f = 1;
    for(ll j = 1; j < pos; j++) f &= (!wires[j][pos] || col[j] != i);
    if(f) col[pos] = i, rec(pos + 1, n, k, col, wires);
  }
}

int main() {
  ll n, m, k, a, b;
  cin >> n >> k >> m;
  vector<vector<bool>> wires(n + 1, vector<bool>(n + 1, 0));
  for(ll i = 0; i < m; i++) {
    cin >> a >> b;
    wires[a][b] = 1; wires[b][a] = 1;
  }
  vll col(n + 1);
  rec(1, n, k, col, wires);
  cout << cnt << '\n';

}
