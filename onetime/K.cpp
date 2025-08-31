#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 10;

ll n, m, k;
char g[N][N];
ll ans[N][N];

void dfs(ll x, ll y, ll st_x, ll st_y, ll cnt, vvll used) {
    used[x][y] = 1;
    if (x != 0 && g[x - 1][y] == '0') {
        if (!used[x - 1][y]) dfs(x - 1, y, st_x, st_y, cnt + 1, used);
        else if (cnt == k && st_x == x - 1 && st_y == y) ans[st_x][st_y] = 1;
    }
    if (x != n - 1 && g[x + 1][y] == '0') {
        if (!used[x + 1][y]) dfs(x + 1, y, st_x, st_y, cnt + 1, used);
        else if (cnt == k && st_x == x + 1 && st_y == y) ans[st_x][st_y] = 1;
    }
    if (y != 0 && g[x][y - 1] == '0') {
        if (!used[x][y - 1]) dfs(x, y - 1, st_x, st_y, cnt + 1, used);
        else if (cnt == k && st_x == x && st_y == y - 1) ans[st_x][st_y] = 1;
    }
    if (y != m - 1 && g[x][y + 1] == '0') {
        if (!used[x][y + 1]) dfs(x, y + 1, st_x, st_y, cnt + 1, used);
        else if (cnt == k && st_x == x && st_y == y + 1) ans[st_x][st_y] = 1;
    }
}

void solve() {
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '0') k++;
            ans[i][j] = 0;
        }
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            vvll used(n, vll (m));
            if (g[i][j] == '0') dfs(i, j, i, j, 1, used);
        }
    }
    bool f = 0;
    for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) if (ans[i][j]) f = 1;
    if (f) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    fastio;
    ll t; cin >> t;
    while (t--) solve();
}
