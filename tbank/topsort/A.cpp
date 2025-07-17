#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;   
int main() {
    bool f = 1;
    ll n, m;
    cin >> n >> m;
    vector<vll> g(n);
    vector<bool> used(n, 0);
    while(m--) {
        ll v1, v2;
        cin >> v1 >> v2;
        v1--, v2--;
        g[v1].push_back(v2);
    }
    for(ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        t--;
        for(ll u : g[t]) {
            if(used[u]) f = 0;
        }
        used[t] = 1;
    }
    cout << (f ? "YES" : "NO") << '\n';
}
