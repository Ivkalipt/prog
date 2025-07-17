//без 3 единиц
//#pragma GCC optimize ("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//#pragma GCC push_options
//#pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

int main() {
    ll n;
    cin >> n;
    vvll dp(3, vll(n+1));
    dp[0][1] = 0;
    dp[1][1] = 1;
    dp[2][1] = 1;
    for(ll i = 2; i <= n; i++) {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = dp[2][i-1];
        dp[2][i] = dp[0][i-1] + dp[1][i-1] + dp[2][i-1];
    }
    cout << dp[0][n] + dp[1][n] + dp[2][n] << "\n";
}