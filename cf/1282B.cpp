// #pragma GCC optimize ("O3, unroll-all-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

ll inf = 1e9 + 7;

void solve1() {
    ll n, p, devnull;
    cin >> n >> p >> devnull;
    vector<vll> dp(n + 1, vll(2)), ans(n + 1, vll(2));
    vll a(n);
    for(ll & c : a) cin >> c;
    sort(all(a));
    dp[0][0] = a[0];
    dp[0][1] = a[0];
    dp[1][0] = a[0] + a[1];
    dp[1][1] = a[1];
    for(ll i = 2; i < n; i++) {
        dp[i][0] = a[i] + min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = min(dp[i - 2][0], dp[i - 2][1]) + a[i];
    }
    for(ll i = n - 1; i > -1; i--) {
        if(min(dp[i][0], dp[i][1]) <= p) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

void solve() {
    ll n, p, k;
    cin >> n >> p >> k;
    vll dp(n + 1, 0), a(n);
    for(ll & c : a) cin >> c;
    sort(all(a));
    dp[0] = a[0];
    for(ll i = 0; i < n; i++) {
        if(i - k > -1)
            dp[i] = dp[i - k + 1] + a[i];
    }
    for(ll i = n - 1; i > -1; i--) {
        if(dp[i] <= p) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n';

}

int main() {
    fastio;
    ll t;
    cin >> t;
    while(t--) solve();
}
