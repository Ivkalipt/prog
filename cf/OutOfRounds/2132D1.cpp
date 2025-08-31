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

constexpr ll N = 15;

ll pow10[N + 1], sum9[N + 1];

ll f(ll x) {
    ll res = 0;
    ll p10 = 1;
    // res += (0 + x % 10) * (x % 10 + 1) / 2;
    for (ll i = 1; i <= log10l(x) + 1; i++) {
        ll now = x / p10 % 10;
        ll left = x % p10;
        res += now * (left + 1) + (now - 1) * now / 2 + sum9[i - 1] * (now - 1) / 2;
        p10 *= 10;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    cout << f(n) << endl;
}

int main() {
    ll c = 1;
    for (ll i = 0; i <= 15; i++) {
        pow10[i] = c;
        c *= 10;
    }
    sum9[1] = 45;
    for (ll i = 2; i <= 15; i++) {
        sum9[i]  = sum9[i - 1] * 10 + sum9[i - 1] * pow10[i - 1];
    }
    solve();
    return 0;
}