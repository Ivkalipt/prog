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
ll cnt = 1;

void dfs(ll v, vvll & g) {
    used[v] = true;
    for(ll & u : g[v]) {
        if(!used[u]) {
            dfs(u, g);
            cnt++;
        }
    }
}

int main() {
    ll n, cnt = 0;
    bool t;
    cin >> n;
    vvll g(n);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> t;
            if(t) {
                g[i].push_back(j);
                g[j].push_back(i);
                cnt++;
            }
        }
    }
    dfs(0, g);
    for(ll i = 0; i < n; i++) {
        if(!used[i]) cout << "NO\n", exit(0);
    }
    if(cnt / 2 != n - 1) cout << "NO\n";
    else cout << "YES\n";
    
}
