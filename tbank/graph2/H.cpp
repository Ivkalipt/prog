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

ll used[1000000];
ll maxd = 0;
vll maxds;

void dfs(ll v, vvll & g, ll d) {
    if (d > maxd) maxds.clear(), maxd = d;
    if (d == maxd) maxds.push_back(v);
    // cout << v << ' ' << maxd << '\n';
    used[v] = true;
    for (ll u : g[v]) {
        if (!used[u]) {
            dfs(u, g, d + 1);
        }
    }
}

int main() {
    fastio;
    ll n, s, t1, t2;
    cin >> n >> s;
    vvll g(n);
    for (ll i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        t1--, t2--;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    dfs(s - 1, g, 0);
    for (ll c : maxds) cout << c + 1 << ' ';
    cout << '\n';
}
