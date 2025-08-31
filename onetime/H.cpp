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
using uint = unsigned int;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 2e5;

int main() {
    uint ans = 0;
    for (int i = 29; i > -1; --i) {
        uint t = 1u << i;
        cout << "? " << t << endl;
        int d;
        if (!(cin >> d)) return 0;
        if (d != 1) ans |= t;
    }
    cout << "! " << ans << endl;
    return 0;
}