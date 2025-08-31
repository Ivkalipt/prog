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
    ll n;
    cin >> n;
    vll a(n), b(n);
    for (ll & x : a) cin >> x;
    for (ll & x : b) cin >> x;
    ll down = 0, up = 0;
    bool f = 1;
    ll cnt = 0;
    while (f) {
        f = 0;
        for (ll j = 0; j < n; j++) {
            if (a[j] > b[j]) {
                a[j]--, f = 1;
                break;
            }
        }
        for (ll j = 0; j < n; j++) {
            if (a[j] < b[j]) {
                a[j]++;
                break;
            }
        }
        cnt++;
    }
    cout << cnt << '\n';

}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}