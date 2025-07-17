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

ll inf = 1e16;

using namespace std;

vector<bool> used(2000, 0);

void dfs(ll v, vvll & g, ll d) {
    used[v] = true;
    // cout << v + 1 << ' ' << d << '\n';
    if (d == 2) return;
    for (ll u : g[v]) {
        dfs(u, g, d + 1);
    }
}

int main() {
    fastio;
    ll n, m, t1, t2;
    cin >> n >> m;
    vvll g(n);
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        t1--, t2--;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    ll erev;
    for (ll i = 0; i < n; i++) {
        dfs(i, g, 0);
        /*for (ll j = 0; j < n; j++) {
            cout << used[j] << ' ';
        }
        cout << '\n';*/
        bool f = 1;
        erev = i;
        for (ll j = 0; j < n; j++) {
            if (!used[j]) f = 0;
        }
        if (f) break;
        used = vector<bool>(2000, 0);
    }
    cout << erev + 1;
    cout << '\n';
}
