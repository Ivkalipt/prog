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
#define mkpair make_pair

const ll inf = 1e18;

int main() {
    // fastio;
    ll n, m;
    cin >> n >> m;
    n += 2, m += 2;
    vector<vll> g(n, vll(m, 1)), d(n, vll(m, inf)), L(n, vll(m, inf)), R(n, vll(m, inf)), U(n, vll(m, inf)), D(n, vll(m, inf));
    for(ll i = 1; i < n - 1; i++)
        for(ll j = 1; j < m - 1; j++)
            cin >> g[i][j];
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(g[i][j] == 2) L[i][j] = 0;
            if(g[i][j] == 1) L[i][j] = -1;
            if(g[i][j] == 0) L[i][j] = L[i][j - 1] + 1;
        }
        for(ll j = m - 1; j > -1; j--) {
            if(g[i][j] == 2) R[i][j] = 0;
            if(g[i][j] == 1) R[i][j] = -1;
            if(g[i][j] == 0) R[i][j] = R[i][j + 1] + 1;
        }
    }
    for(ll j = 0; j < m; j++) {
        for(ll i = 0; i < n; i++) {
            if(g[i][j] == 2) U[i][j] = 0;
            if(g[i][j] == 1) U[i][j] = -1;
            if(g[i][j] == 0) U[i][j] = U[i - 1][j] + 1;
        }
        for(ll i = n - 1; i > -1; i--) {
            if(g[i][j] == 2) D[i][j] = 0;
            if(g[i][j] == 1) D[i][j] = -1;
            if(g[i][j] == 0) D[i][j] = D[i + 1][j] + 1;
        }
    }

    d[1][1] = 0;
    queue<pll> q;
    q.push({1, 1});
    map<pll, char> p;
    bool f = 1;
    while(!q.empty()) {
        pll v = q.front();
        ll i = v.F, j = v.S;
        q.pop();
        ll rc = R[i][j], lc = L[i][j], uc = U[i][j], dc = D[i][j];
        if(g[i][j] == 2) continue;
        if(p[{i, j}] == 'D' || p[{i, j}] == 'U' || f) {
            if(d[i][j] + 1 < d[i][j + rc]) {
                d[i][j + rc] = d[i][j] + 1;
                q.push({i, j + rc});
                p[{i, j + rc}] = 'L';
            }
            if(d[i][j] + 1 < d[i][j - lc]) {
                d[i][j - lc] = d[i][j] + 1;
                q.push({i, j - lc});
                p[{i, j - lc}] = 'R';
            }
        }


        if(p[{i, j}] == 'R' || p[{i, j}] == 'L' || f) {
            if(d[i][j] + 1 < d[i + dc][j]) {
                d[i + dc][j] = d[i][j] + 1;
                q.push({i + dc, j});
                p[{i + dc, j}] = 'U';
            }
            if(d[i][j] + 1 < d[i - uc][j]) {
                d[i - uc][j] = d[i][j] + 1;
                q.push({i - uc, j});
                p[{i - uc, j}] = 'D';
            }
            f = 0;
        }
    }
    /*for(vll c : d) {
        for(ll vc : c) cout << vc << ' ';
        cout << '\n';
    }*/
    ll ans = inf;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(g[i][j] == 2) ans = min(ans, d[i][j]);
        }
    }
    cout << ans << '\n';
} 
