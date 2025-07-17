#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define F first
#define S second

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;

const ll maxn = 1e5;

int main() {
    ll n, k, m;
    cin >> n >> k >> m;
    vll a(n);
    for (ll & c : a) cin >> c;
    ll curr_sum = 0;
    for (ll i = 0; i <= k; i++)
        curr_sum += a[i];
    if (curr_sum == m) { cout << 1 << '\n'; return 0; }
    for (ll i = k; i < n - 1; i++) {
        // cout << curr_sum << '\n';
        curr_sum -= a[i - k];
        curr_sum += a[i + 1];
        if (curr_sum == m) { cout << i - k + 2 << '\n'; return 0; }
    }
    // cout << curr_sum << '\n';
    cout << 0 << '\n';
}