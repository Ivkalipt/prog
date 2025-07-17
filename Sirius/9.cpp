//мячик
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
#define F first
#define S second

using namespace std;

int main() {
    ll n;
    cin >> n;
    vll dp(n+10);
    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(ll i = 4; i < n+1; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout << dp[n];

}