// #pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using u64 = unsigned long long;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main() {
  string s;
  vector<pair<string, ll>> lines;
  vll level = {0};
  ll cnt = 1;
  bool flag = 0;
  bool used[101];
  do {
    getline(cin, s);
    ll cnt_ws = 0;
    for (; cnt_ws < sz(s); cnt_ws++)
      if (s[cnt_ws] != ' ')
        break;
    lines.emplace_back(s, cnt_ws);
  } while (s != "exit()");
  
  for (ll i = 0; i < sz(lines); i++) {
    string s = lines[i].F;
    ll cnt_ws = lines[i].S;
    if (s == "") continue;
    
    if (flag) {
      if (cnt_ws <= level.back()) {
        cout << cnt << '\n';
        return 0;
      }
      level.push_back(cnt_ws);
      flag = 0;
    }

    if (s.back() == ':') {
      flag = 1;
    }
    if (s[sz(s) - 1] == ':' && s[sz(s) - 2] == 'e' && s[sz(s) - 3] == 's') {
      bool flag2 = 0;
      for (ll j = cnt - 1; j >= 0; j--) {
        if (lines[j].F[lines[j].S] == 'i' && cnt_ws == lines[j].S && !used[j]) {
          flag2 = 1;
          used[j] = true;
          break;
        }
      }
      if (!flag2) {
        cout << cnt << '\n';
        return 0;
      }
    }

    while (!level.empty() && cnt_ws != level.back()) {
      level.pop_back();
    }
    if (level.empty()) {
      cout << cnt << '\n';
      return 0;
    }
    
    cnt++;
  }
  cout << 0 << '\n';
}
