#include <algorithm>
#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

bool used[10000];
vll tops;

void dfs1(ll v, vvll & g) {
    used[v] = true;
    for(ll u : g[v]) {
        if(!used[u]) dfs1(u, g);
    }
    tops.push_back(v);
}

ll c[20000];
ll t = 0;
void dfs2(ll v, vvll & g) {
    used[v] = true;
    c[t]++;
    for(ll u : g[v]) {
        if(!used[u]) dfs2(u, g);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vvll g1(n), g2(n);
    while(m--) {
        ll v, u;
        cin >> v >> u;
        swap(v,u);
        v--, u--;
        g1[v].push_back(u);
        g2[u].push_back(v);
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i])
            dfs1(i, g1);
    }
    reverse(all(tops));
    for(ll i = 0; i < n; i++) used[i] = false;
    ll ans = 0;
    for(ll u : tops) {
        if(!used[u]) {
            dfs2(u, g2);
            ans += (1 + (c[t] > 1));
            t++;
        }
    }
    cout << ans << '\n';
}
