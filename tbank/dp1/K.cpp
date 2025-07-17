#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
    fastio;
    ll n;
    cin >> n;
    vll dp(n + 3, 0);
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for(ll i = 3; i < n + 3; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    cout << dp[n + 2] << '\n';
}
