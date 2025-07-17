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

bool used[100];
ll colors[100];
vll table;

struct node {
    ll v, color;
};

void dfs(ll v, vvll & g, ll color) {
    used[v] = true;
    colors[v] = color;
    for(auto u : g[v]) {
        if(!used[u]) {
            dfs(u, g, -color);
        }
        else {
            if(colors[v] == colors[u]) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
}

int main() {
    ll n, m, t1, t2, k = 0;
    vll y;
    cin >> n >> m;
    vvll g(n);
    for(ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        g[t1-1].push_back(t2-1);
        g[t2-1].push_back(t1-1);
    }

    for(ll i = 0; i < n; i++)
        if(!used[i])
            dfs(i, g, 1);
    cout << "YES\n";
    for(ll i = 0; i < n; i++)
        if(colors[i] == 1) 
            cout << i + 1 << ' ';
    cout << '\n';
        
}
