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

using namespace std;

vvll d;

void bfs(pll s, vector<string> & g, ll n, ll m) {
    queue<pll> q;
    d[s.F][s.S] = 0;
    q.push({s.F, s.S});
    while (!q.empty()) {
        pll v = q.front();
        q.pop();
        ll i = v.F, j = v.S, l = d[i][j] + 1;
        // cout << i << ' ' << j << '\n';
        if (i < n - 1 && d[i + 1][j] == -1 && g[i + 1][j] == '.') d[i + 1][j] = l, q.push({i + 1, j});
        if (i > 0 && d[i - 1][j] == -1 && g[i - 1][j] == '.') d[i - 1][j] = l, q.push({i - 1, j});
        if (j < m - 1 && d[i][j + 1] == -1 && g[i][j + 1] == '.') d[i][j + 1] = l, q.push({i, j + 1});
        if (j > 0 && d[i][j - 1] == -1 && g[i][j - 1] == '.') d[i][j - 1] = l, q.push({i, j - 1});
    }
}

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    d.resize(n, vll(m, -1));
    vector<string> g(n);
    for (string & c : g) cin >> c;
    bfs({0, 0}, g, n, m);
    /*for(vll c : d) {
        for(ll v : c) {
            cout << v << ' ';
        }
        cout << '\n';
    }*/
    cout << d[n - 1][m - 1] << '\n';
}


