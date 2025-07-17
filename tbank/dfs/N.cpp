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

vector<bool> used;

void dfs(ll v, vector<vector<pll>> & g, ll d) {
    used[v] = true;
    for(pll u : g[v]) {
        if(!used[u.F] && u.S <= d) {
            dfs(u.F, g, d);
        }
    }
}

bool check(ll v, ll f, vector<vector<pll>> & g, ll d) {
    used.assign(g.size(), 0);
    dfs(v, g, d);
    /*for(bool c : used) cout << c << ' ';
    cout << '\n';*/
    return used[f];
}

int main() {
    ll n, m, maxw = -1;
    cin >> n >> m;
    vector<vector<pll>> g(n);
    for(ll i = 0; i < m; i++) {
        ll v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--, v2--;
        g[v1].push_back({v2, w});
        g[v2].push_back({v1, w});
        if(w > maxw) maxw = w;
    }
    ll s, f;
    cin >> s >> f;
    s--, f--;
    ll l = 0, r = maxw;
    while(r - l > 1) {
        ll mid = (l + r) / 2;
        if(check(s, f, g, mid)) {
            r = mid;
        }
        else {
            l = mid;
        }
        // cout << l << ' ' << r << '\n';
    }
    cout << r << '\n';
}
