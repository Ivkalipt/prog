#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()
#define S second
#define F first

using namespace std;
using ll = long long;
using vll = vector<long long>;

int n, m, s;
vector<vector<int>> g, gr;
vector<int> order;
vector<int> comp;
vector<char> used;

void dfs1(int v) {
  used[v] = 1;
  for (int to : g[v])
    if (!used[to])
      dfs1(to);
  order.push_back(v);
}

void dfs2(int v, int cid) {
  comp[v] = cid;
  for (int to : gr[v])
    if (comp[to] == -1)
      dfs2(to, cid);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  if (!(cin >> n >> m >> s))
    return 0;
  g.assign(n, {});
  gr.assign(n, {});
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  used.assign(n, 0);
  for (int v = 0; v < n; ++v)
    if (!used[v])
      dfs1(v);

  comp.assign(n, -1);
  int k = 0;
  for (int i = (int)order.size() - 1; i >= 0; --i)
    if (comp[order[i]] == -1)
      dfs2(order[i], k++);

  if (k == 1) {
    cout << 0 << '\n';
    return 0;
  }

  vector<int> indeg(k, 0);
  for (int v = 0; v < n; ++v) {
    int cv = comp[v];
    for (int to : g[v]) {
      int cu = comp[to];
      if (cv != cu)
        ++indeg[cu];
    }
  }

  int start = comp[s];
  int ans = 0;
  for (int c = 0; c < k; ++c)
    if (indeg[c] == 0 && c != start)
      ++ans;

  cout << ans << '\n';
  return 0;
}
