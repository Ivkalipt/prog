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

const int MAXN = 2e5 + 1;

void solve() {
    ll n;
    cin >> n;
    vll a(n), b(n), c(n), d(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    ll total_free_zero = 0, sum_operations = 0;
    rep(i, 0, n) {
        if (b[i] > d[i]) total_free_zero += a[i], a[i] = 0;
        else if (c[i] < a[i]) total_free_zero += a[i] - c[i], a[i] = c[i];
    }
    ll ind_without_ch_1 = -1;
    rep(i, 0, n) {
        if (c[i] > a[i]) {
            total_free_zero -= c[i] - a[i];
            sum_operations += c[i] - a[i];
            a[i] = c[i];
        }
        if (b[i] <= d[i]) ind_without_ch_1 = i;
    }
    sum_operations += total_free_zero;
    rep(i, 0, n) {
        if (b[i] > d[i]) {
            sum_operations += b[i] - d[i];
        }
    }
    sum_operations += total_free_zero;
    cout << sum_operations << '\n';
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}