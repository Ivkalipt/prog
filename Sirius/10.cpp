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
    vll dp(n+1, 0);
    for(ll i = 1; i <= n; i++) {
        ll c = dp[i-1];
        if(i%2==0) c = min(c, dp[i/2]);
        if(i%3==0) c = min(c, dp[i/3]);
        dp[i] = c+1;
    }
    cout << dp[n]-1;
}