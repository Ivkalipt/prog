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

using namespace std;

ll maxd = 0;

ll used[100];

void dfs(ll v, vvll & g) {
    used[v] = true;
    for(ll u : g[v]) {
        if(!used[u])
            dfs(u, g);
    }
} 

int main() {
    ll n;
    ll l = 0, t;
    cin >> n;
    vvll g(n);
    for(ll i = 0; i < n; i++) {
        cin >> t;
        g[t - 1].push_back(i);
    }
    /*for(vll c : g) {
        for(ll v : c) {
            cout << v << ' ';
        }
        cout << '\n';
    }*/
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        dfs(i, g);
        cnt++;
    }
    cout << cnt << '\n';
    
}
