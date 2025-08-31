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
    for (ll i = 0; i < n; i++) {

        if (i & 1) {
            if (i == n - 1) cout << 2 << ' ';
            else cout << 3 << ' ';
        }
        else cout << -1 << ' ';
    }
    cout << '\n';
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}