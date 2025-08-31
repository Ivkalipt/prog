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
    ll n, m;
    cin >> n >> m;
    if (n * (n - 1) / 2 < m) {
        cout << -1 << '\n';
        return;
    }
    cout << max(1LL, n - m) << ' ';
    ll l = 0, r = n + 1, key = n;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (((mid * (mid - 1)) >> 1) >= m) key = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << n - key + 1 << '\n';


}

int main() {
    fastio; // убрать на интерактивках
    solve();
    return 0;
}