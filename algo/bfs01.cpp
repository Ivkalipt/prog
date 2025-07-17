#pragma GCC optimize ("O3,unroll-loops")
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

vll d(100000, -1);

void bfs(ll s, vector<vector<pll>> & g) {
    d[s] = 0;
    deque<ll> q;
    q.push_back(s);
    while(!q.empty()) {
        ll v = q.back();
        q.pop_back();
        for(pll u : g[v]) {
            d[u.S] > d[v] + 
            if(u.F == 0) {
                q.push_back(u.S);
            }
            else {
                q.push_front(u.S);
            }
        }
    }
}
