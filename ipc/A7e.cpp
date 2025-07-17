// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

int main() {
    fastio;
    ll n;
    cin >> n;
    vll dp(n+1);
    if(n == 1) {
        cout << 1 << "\n";
        return 0;
    }
    if(n == 2) {
        cout << 2 << "\n";
        return 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(ll i = 3; i <= n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout << dp[n];
    cout << "\n";
    return 0;
}