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

const ll inf = 1e18;

void floyd(vector<vll> & g, ll n) {
    for(ll k = 0; k < n; k++) {
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    ll n, m;
    cin >> n;
    vector<vll> g(n, vll(n));
    for(vll & c : g) 
        for(ll & v : c)
            cin >> v, v = (v == 0 ? inf : 1);
    floyd(g, n);
    ll ans = -inf;
    for(vll & c : g) {
        for(ll & v : c)
            cout << (v == inf ? 0 : 1) << ' ';
        cout << '\n';
    }
}
