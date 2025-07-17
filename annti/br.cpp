// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

v(bool) used(10e5, 0);

void dfs(ll v, vv(ll) g) {
    used[v] = 1;
    for(auto u:g[v]) {
        if(!used[u]) {
            dfs(u, g);
        }
    }
}

int main() {
    ll n, m, t1, t2, k = 0;
    cin >> n >> m;
    vv(ll) g(n);
    v(ll) a;
    for(ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        g[t1-1].push_back(t2-1);
        g[t2-1].push_back(t1-1);
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i]) {
            a.push_back(i); a.push_back(i);
            k++;
            dfs(i, g);
        }
    }
    cout << k << "\n";
    for(ll i = 1; i < n-3; i++) {
        cout << a[i] << " " << a[i+1] << "\n";
    }

}