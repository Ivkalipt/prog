#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

void floyd(vector<vll> & g, vector<vll> & pointer, ll n) {
    for(ll k = 0; k < n; k++) {
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                if(g[i][k] + g[k][j] < g[i][j] && g[i][k] < inf && g[k][j] < inf) {
                    g[i][j] = g[i][k] + g[k][j];
                    pointer[i][j] = pointer[k][j];
                }
            }
        }
    }
}

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vector<vll> d(n, vll(n, inf)), pointer(n, vll(n, -1));
    for(ll i = 0; i < n; i++) d[i][i] = 0;
    for(ll i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        d[v][u] = w;
    }
    floyd(d, pointer, n);
    ll indinf = -1;
    for(ll i = 0; i < n; i++) {
        if(d[i][i] < 0) indinf = i;
    }
    if(indinf < 0) {
        ll ans = -inf;
        for(vll & c : d) {
            for(ll & v : c)
                cout << (v == inf ? "INF" : to_string(v)) << ' ';
            cout << '\n';
        }
    }
    else {
        vll ans;
        ll ind = indinf;
        ind = pointer[ind][ind];
        while(ind != indinf) {
            ans.push_back(ind);
            ind = pointer[ind][indinf];
        }
        cout << ans.size() << '\n';
        for(ll c : ans) cout << c << ' ';
        cout << '\n';
    }
}
