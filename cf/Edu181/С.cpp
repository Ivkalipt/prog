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

ll primes[] = {35, 21, 15, 14, 10, 6, 210, 7, 5, 3, 2, 70, 105, 42, 30};

ll f(ll x) {
    ll res = 0;
    for (ll i = 0; i < 7; i++)
        res += x / primes[i];
    for (ll i = 7; i < 15; i++)
        res -= x / primes[i];
    return x + res;
}

void solve() {
    ll l, r;
    cin >> l >> r;
    cout << f(r) - f(l - 1) << '\n';

}

int main() {
    ll t; cin >> t; while (t--) solve();
}