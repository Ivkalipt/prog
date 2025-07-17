// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

int main() {
    ll n;
    cin >> n;
    vll x(n);
    for(ll &c : x) cin >> c;
    sort(all(x));
    vll dp(n + 4);
    dp[1] = x[1] - x[0];
    dp[2] = x[2] - x[0];
    dp[3] = x[3] - x[2] + x[1] - x[0];
    for(ll i = 4; i < n; i++) dp[i] = min({x[i - 1] - x[i - 2] + dp[i - 3], dp[i - 2]}) + x[i] - x[i - 1];
    cout << dp[n - 1] << '\n';
}
