#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> rank_;
vector<int> delta; // Дополнительный счетчик для корня
vector<int> size_; // Размер множества

int find(int x) {
  if (parent[x] != x) {
    int root = find(parent[x]);
    delta[x] += delta[parent[x]]; // Переносим счетчик
    parent[x] = root;
  }
  return parent[x];
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  if (rank_[x] < rank_[y]) {
    swap(x, y);
  }
  parent[y] = x;
  delta[y] -= delta[x]; // Корректируем счетчик
  size_[x] += size_[y];
  if (rank_[x] == rank_[y]) {
    rank_[x]++;
  }
}

int get_count(int x) {
  find(x); // Обновляем счетчики
  return delta[x];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  parent.resize(n + 1);
  iota(parent.begin(), parent.end(), 0);
  rank_.assign(n + 1, 0);
  delta.assign(n + 1, 0);
  size_.assign(n + 1, 1);

  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y;
      cin >> x >> y;
      x = find(x);
      y = find(y);
      if (x != y) {
        if (size_[x] < size_[y]) {
          swap(x, y);
        }
        delta[y]++; // Увеличиваем счетчик для меньшего множества
        unite(x, y);
      }
    } else if (type == 2) {
      int x, y;
      cin >> x >> y;
      cout << (find(x) == find(y) ? "YES" : "NO") << '\n';
    } else if (type == 3) {
      int x;
      cin >> x;
      find(x); // Обновляем счетчики
      cout << delta[x] << '\n';
    }
  }

  return 0;
}
