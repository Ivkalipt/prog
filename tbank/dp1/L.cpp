#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>

using namespace std;

int main() {
    ll n;
    cin >> n;
    vvll dp(n + 1, vll(n + 1));
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++)
        for (ll j = 1; j <= i; j++)
            for (ll k = 0; k < j; k++)
                dp[i][j] += dp[i - j][k];
    ll s = 0;
    for(ll c : dp[n]) s += c;
    cout << s << '\n';
}
