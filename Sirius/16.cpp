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
    ll k, p;
    cin >> k >> p;
    vll dp(k+1);
    dp[2] = 1;
    for(ll i = 3; i <= k; i++) {
        if(i == 10e6) {
            cout << dp[i-1] + dp[i/2];
        }
        dp[i] = dp[i-1];
        if(i%2==0) {
            dp[i] += dp[i/2];
        }
    }
    cout << dp[k]%p;
    cout << "\n";
}