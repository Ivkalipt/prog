#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define F first
#define S second

using namespace std;

bool used[100], iter = 0, flag = 0;
short parity[100];

int dfs(ll v, vvll g, short color) {
    used[v] = true;
    parity[v] = color;
    ll k = 0;
    for(auto u:g[v]) {
        if(!used[u]) {
            dfs(u, g, -color);
        }
        else
        {
            if(parity[u] == parity[v]) {
                flag = 1;
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    ll n, m, t1, t2;
    cin >> n >> m;
    vvll g(n);
    for(ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        t1--; t2--;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i]) dfs(i, g, 1);
    }
    if(flag) cout << "NO";
    else cout << "YES";

}