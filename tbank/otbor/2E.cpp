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
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll SS = 0, Ssq = 0;
    for (ll i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        Ssq = (Ssq + 2 * x * SS + i * x % MOD * x) % MOD;
        SS = (SS + x * i) % MOD;
        cout << Ssq << " ";
    }
}