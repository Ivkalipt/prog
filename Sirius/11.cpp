//без 2 нулей
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
// #define vll  vector<ll>
// #define vvll vector<vector<ll>>
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> dp(n+1);
    dp[1].F = 1;
    dp[1].S = k-1;
    for(ll i = 2; i <= n; i++) {
        dp[i].F = dp[i-1].S;
        dp[i].S = (dp[i-1].S + dp[i-1].F) * (k-1);
    }
    cout << dp[n].F + dp[n].S << "\n";
}