#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 2e5;

void solve() {
    ll n;
    cin >> n;
    vll dpy(n + 1), dpgl(n + 1), dpcogl(n + 1), dpb(n + 1);
    ll y = 1, gl = 10, cogl = 20, b = 2;
    dpgl[1] = gl;
    dpcogl[1] = cogl;
    dpb[1] = 0;
    dpy[1] = y;
    for (ll i = 2; i <= n; i++) {
        dpgl[i] = ((dpcogl[i - 1] + dpy[i - 1] + dpb[i - 1]) * gl) % MOD;
        dpcogl[i] = ((dpgl[i - 1]) * (cogl)) % MOD;
        dpb[i] = ((dpcogl[i - 1]) * b) % MOD;
        dpy[i] = ((dpgl[i - 1]) * y) % MOD;
    }
    cout << (dpgl[n] + dpcogl[n] + dpy[n] + dpb[n]) % MOD << endl;


}

int main() {
    fastio; // убрать на интерактивках
    solve();
    return 0;
}