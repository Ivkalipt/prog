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

int main() {
    ll n, m, q;
    cin >> n >> m >> q;
    ll root = sqrtl(n);
    vvll g(n);
    vll neigh(n, 0);
    vll ad(n, 0), d(n);
    for (ll & c : d) cin >> c;
    for (ll i = 0; i < m; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        g[u].push_back(v);
        g[v].push_back(u);
        neigh[u]++;
        neigh[v]++;
    }
    vvll g2(n);
    for (ll i = 0; i < n; i++) {
        for (ll u : g[i]) {
            if (neigh[u] >= root) {
                g2[i].push_back(u);
            }
        }
        /*for(ll c : g2[i]) {
            cout << c << ' ';
        }
        cout << '\n';*/
    }
    while (q--) {
        char type;
        cin >> type;
        if (type == '+') {
            ll v, x;
            cin >> v >> x;
            v--;
            if (neigh[v] >= root) {
                ad[v] += x;
            } else {
                for (ll u : g[v]) {
                    d[u] += x;
                }
            }
        }
        if (type == '?') {
            ll v;
            cin >> v;
            v--;
            ll ans = d[v];
            for (ll u : g2[v]) {
                ans += ad[u];
            }
            cout << ans << '\n';
        }
    }
}
