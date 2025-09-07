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
using vpll = vector<pll>;
using vvll = vector<vll>;

const int MAXN = 100000;
vector<pair<int, int>> graph[MAXN]; // (neighbor, weight)
int investment[MAXN];
bool visited[MAXN];

void dfs(int u) {
  visited[u] = true;
  for (auto edge : graph[u]) {
    int v = edge.first;
    int c = edge.second;
    if (!visited[v]) {
      if (investment[u] != c) {
        investment[v] = c;
      } else {
        if (c != 1) {
          investment[v] = 1;
        } else {
          investment[v] = 2;
        }
      }
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--; v--;
    graph[u].push_back({v, c});
    graph[v].push_back({u, c});
  }

  memset(visited, false, sizeof(visited));
  investment[0] = 1;
  dfs(0);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      cout << "No\n";
      return 0;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << investment[i] << '\n';
  }

  return 0;
}