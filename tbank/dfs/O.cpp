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

bool used[100000];
vll d(100000);
vll ans;

void dfs(ll v, vvll & g, vll & p) {
    used[v] = true;
    d[v] = p[v];
    for(ll u : g[v]) {
        if(!used[u])
            dfs(u, g, p), d[v] += d[u];
    }
    ans.push_back(v);
}

int main() {
    ll n;
    cin >> n;
    vvll g(n);
    vll p(n);
    for(ll & c : p) cin >> c;
    for(ll i = 0; i < n; i++) {
        ll nn;
        cin >> nn;
        g[i].resize(nn);
        for(ll j = 0; j < nn; j++) cin >> g[i][j], g[i][j]--;
    }
    dfs(0, g, p);
    cout << d[0] << ' ' << ans.size() << '\n';
    for(ll c : ans) cout << c + 1 << ' ';
    cout << '\n';
}
