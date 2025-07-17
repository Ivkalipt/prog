#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

vll d(1e5, inf), p(1e5, -1);

void dijkstra(ll s, vector<vpll> & g) {
    d[s] = 0;
    set<pll> q;
    q.insert({0, s});
    while(!q.empty()) {
        ll v = q.begin() -> S;
        q.erase(*q.begin());
        for(pll u : g[v]) {
            if(d[u.S] > d[v] + u.F) {
                q.erase({d[u.S], u.S});
                d[u.S] = d[v] + u.F;
                p[u.S] = v;
                q.insert({d[u.S], u.S});
            }
        }
    }
}

int main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vpll> g(n);
    for(ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].push_back({w, u});
        g[u].push_back({w, v});
    }
    dijkstra(s, g);
    if(d[t] == inf) cout << -1 << '\n';
    else {
        cout << d[t] << '\n';
        ll ind = t;
        vll ans;
        ans.push_back(ind);
        while(p[ind] != -1) {
            ans.push_back(p[ind]);
            ind = p[ind];
        }
        reverse(all(ans));
        cout << ans.size() << '\n';
        for(ll c : ans) cout << c + 1 << ' ';
        cout << '\n';

    }
}
