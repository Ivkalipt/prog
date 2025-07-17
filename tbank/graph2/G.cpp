#pragma GCC optimize("O3,unroll-loops")
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

ll inf = 1e16;

using namespace std;

ll colors[100000];

void dfs(ll v, vvll & g) {
    for (ll & u : g[v]) {
        if (colors[u] == 0) {
            colors[u] = 1;
            dfs(u, g);
            colors[u] = 2;
        } else if (colors[u] == 1) {
            cout << 1 << '\n';
            exit(0);
        }
    }
}

int main() {
    fastio;
    ll n, m, t1, t2;
    cin >> n >> m;
    vvll g(n);
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        t1--, t2--;
        g[t1].push_back(t2);
    }
    for (ll i = 0; i < n; i++) {
        if (!colors[i]) {
            colors[i] = 1;
            dfs(i, g);
            colors[i] = 2;
        }
    }
    cout << 0 << '\n';
}
