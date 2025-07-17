#pragma gcc optimize ("O3,unroll-loops")
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

bool used[100001];

vll a;

void dfs(ll v, vvll & g) {
    used[v] = true;
    a.push_back(v);
    for(ll u : g[v]) {
        if(!used[u])
            dfs(u, g);
    }
}

int main() {
    ll n, m, t1, t2;
    cin >> n >> m;
    vvll g(n);
    for(ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        t1--, t2--;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    vvll components;
    for(ll i = 0; i < n; i++) {
        if(!used[i]) {
            dfs(i, g);
            components.push_back(a);
            a.clear();
        }
    }
    cout << components.size() << '\n';
    for(vll & c : components) {
        cout << c.size() << '\n';
        for(ll & v : c) cout << v + 1 << ' ';
        cout << '\n';
    }
}
