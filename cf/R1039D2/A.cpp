#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

void solve() {
    ll n, c;
    cin >> n >> c;
    vll a(n);
    for (ll & x : a) cin >> x;
    sort(rall(a));
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] <= c) c /= 2;
        else ans++;
    }
    cout << ans << '\n';
}

int main() { ll t; cin >> t; while (t--) solve(); }