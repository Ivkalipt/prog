#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>

using namespace std;

int main() {
    ll n, s=0;
    cin >> n;
    vvll dp(n + 1, vll(n + 1));
    dp[0][0] = 1;
    for(ll i = 1; i < n + 1; i++) {
        for (ll j = 1; j <= i; j++) {
            for (ll k = 0; k <= j - 1; k++) {

                dp[i][j] += dp[i-j][k];
            }
        }
    }
    for(ll i = 0; i < n+1; i++) {
        s+=dp[n][i];
    }
    cout << s;

}