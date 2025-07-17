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

ll used[100000];

vector<pll> a;

void dfs(ll v, vvll & g) {
    used[v] = true;
    for(ll u : g[v]) {
        if(!used[u])
            dfs(u, g), a.push_back({u, v});

    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vvll g(n);
    while(m--) {
        ll v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(0, g);
    for(pll c : a) cout << c.F + 1 << ' ' << c.S + 1 << '\n';
    

}
