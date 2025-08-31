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

void solve() {
    map<pll, ll> mp1, mp2;
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        pll to = {max(t % k, k - t % k), min(t % k, k - t % k)};
        if (!mp1.count(to)) mp1[to] = 1;
        else mp1[to]++;
    }
    for (ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        pll to = {max(t % k, k - t % k), min(t % k, k - t % k)};
        if (!mp2.count(to)) mp2[to] = 1;
        else mp2[to]++;
    }
    for (pair<pll, ll> p : mp1) {
        if (mp2.count(p.F) && p.S == mp2[p.F]) continue;
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}