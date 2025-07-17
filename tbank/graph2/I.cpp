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

ll used[200000];
vll p(200000, -1);

void dfs(ll v, vvll & g) {
    used[v] = true;
    for (ll & u : g[v]) {
        if (!used[u]) {
            p[u] = v;
            dfs(u, g);
        }
    }
}

int main() {
    ll n, t;
    cin >> n;
    vvll g(n);
    for (ll i = 1; i < n; i++) {
        cin >> t;
        g[t - 1].push_back(i);
    }
    dfs(0, g);
    ll ind = n - 1;
    vll ans;
    ans.push_back(ind);
    while (p[ind] != -1) {
        ans.push_back(p[ind]);
        ind = p[ind];
    }
    reverse(all(ans));
    for (ll c : ans) cout << c + 1 << ' ';
    cout << '\n';
}
