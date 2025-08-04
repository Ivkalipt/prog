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
    ll a, b, k;
    cin >> a >> b >> k;
    ll x = max(
        min(a, a / __gcd(a, b)),
        min(b, b / __gcd(a, b))
        );
    if (x > k) cout << 2 << '\n';
    else cout << 1 << '\n';
}

int main() {
    ll t; cin >> t; while (t--) solve();
}