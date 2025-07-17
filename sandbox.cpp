#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e18;

int main() {
  ll a, b;
  cin >> a >> b;
  for (ll i = 0; i < 10; i++) {
    a += 2;
  }
  cout << a << '\n';
  return 0;
}
