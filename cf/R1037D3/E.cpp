#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

void solve() {
    ll n;
    cin >> n;
    vll p(n), s(n), a(n);
    for (ll & c : p) cin >> c;
    for (ll & c : s) cin >> c;
    rep(i, 0, n) {
        a[i] = lcm(p[i], s[i]);
        cout << a[i] << ' ';
    }
    rep(i, 1, n) {
        if (p[i - 1] % a[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    rep(i, 0, n - 1) {
        if (s[i + 1] % a[i] != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    fastio;
    ll t;
    cin >> t;
    while (t--) solve();
}