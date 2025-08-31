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
    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for (ll & x : a) cin >> x;
    for (ll & x : b) cin >> x;
    vector<bool> used(n);
    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] == b[i]) used[i] = 1;
        if ((a[i] ^ a[i + 1]) == b[i]) {
            a[i] = b[i];
            used[i] = 1;
        }
    }
    if (a[n - 1] == b[n - 1]) used[n - 1] = 1;
    for (ll i = n - 2; i >= 0; --i) {
        if (a[i] == b[i]) used[i] = 1;
        else if ((a[i] ^ a[i + 1]) == b[i]) {
            used[i] = 1;
            a[i] = b[i];
            if (i != 0) {
                if ((a[i - 1] ^ a[i]) == b[i - 1]) {
                    used[i - 1] = 1;
                    a[i - 1] = b[i - 1];
                }
            }
        }
    }
    bool f = 1;
    for (ll i = 0; i < n; ++i) if (!used[i]) f = 0;
    if (f) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    fastio;
    ll t;
    cin >> t;
    while (t--) solve();
}