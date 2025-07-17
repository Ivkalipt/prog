#include <algorithm>
#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    vvll dp(k + 1, vll(2, 1)), dp1(k + 1, vll(2));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= k; j++) {
            for(ll l = 1; l < j; l++) {
                dp1[j][0] += dp[l][1];
            }
            for(ll l = j + 1; l <= k; l++) {
                dp1[j][1] += dp[l][0];
            }
        }
        cout << dp[k][0] << ' ' << dp[k][1] << '\n';
        dp = dp1;
    }
    
}
