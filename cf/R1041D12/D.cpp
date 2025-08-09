#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 2e5;

ll fact[N + 1];

void dfs(bool & flag, ll v, vvll & g, ll color, vector<bool> & used, vll & parity) {
    used[v] = true;
    parity[v] = color;
    for(auto u : g[v]) {
        if(!used[u]) {
            dfs(flag, u, g, -color, used, parity);
        }
        else
        {
            if(parity[u] == parity[v]) {
                flag = 1;
                return;
            }
        }
    }
}

void dfs2(ll prev, ll v, const vvll & g, vector<bool> & used2, vll & cnt) {
    used2[v] = true;
    bool f = 0;
    for (const ll u : g[v]) {
        if(!used2[u]) {
            dfs2(v, u, g, used2, cnt);
        }
        if (u != prev) f = 1;
    }
    if (!f && prev != -1) cnt[prev]++;
}

void solve() {
    ll n, m, t1, t2;
    cin >> n >> m;
    vvll g(n);
    vector<bool> used(n + 1), used2(n + 1);
    bool iter = 0, flag = 0;
    vll parity(n + 1), cnt(n + 1);
    for(ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        t1--; t2--;
        g[t1].push_back(t2);
        g[t2].push_back(t1);
    }
    if (n == 2) {
        cout << 2 << '\n';
        return;
    }
    for(ll i = 0; i < n; i++) {
        if(!used[i]) dfs(flag, i, g, 1, used, parity);
    }
    if(flag) {
        cout << 0 << '\n';
        return;
    }
    for(ll i = 0; i < n; i++) {
        if(!used2[i]) dfs2(-1, i, g, used2, cnt);
    }
    ll cnt_n_0 = 0;
    for (ll x : cnt) {
        if (x) cnt_n_0++;
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (cnt[i] > 1) {
            ans += fact[cnt[i]];
            ans %= MOD;
        }
    }
    ans = (ans * 2) % MOD;
    if (cnt_n_0 != 1) ans = (ans * 2) % MOD;
    cout << ans << '\n';
    //for (ll x : cnt) cout << x << ' ';
    //cout << '\n';
}

int main() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll t;
    cin >> t;
    while(t--) solve();
}
