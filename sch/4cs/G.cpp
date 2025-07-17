// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

int main() {
    ll n;
    cin >> n;
    vll dp(n + 4);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(ll i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1] - dp[i - 3] * 2;
    }
    // cout << dp[n] << '\n';
    for(ll i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }
}
