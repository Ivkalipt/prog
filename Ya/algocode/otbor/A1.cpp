#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;

const ll MAXN = 1e5;

bool used[MAXN];
ll money[MAXN];

void dfs(ll v, vector<vpll> & g) {
    used[v] = true;
    for (pll x : g[v]) {
        ll u = x.F;
        ll w = x.S;
        if (!used[u]) {
            if (money[v] != w) {
                money[u] = w;
            }
            else {
                if (w != 1) money[u] = 1;
                else money[u] = 2;
            }
            dfs(u, g);
        }
    }
}

int main()  {
    ll n, m;
    cin >> n >> m;
    vector<vpll> g(n);
    while (m--) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    money[0] = 1;
    dfs(0, g);
    for (ll i = 0; i < n; i++) {
        if (!used[i]) {
            cout << "No\n";
            return 0;
        }
    }
    for (ll i = 0; i < n; i++) cout << money[i] << '\n';
}