#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<vll> dp(3, vll(n, 0));
    ll t;
    cin >> t;
    if(t == 3) {
        dp[1][0] = 1;
        dp[2][0] = 1;
    }
    else if(t == 2 || t == 1) {
        dp[t][0] = 1;
    }
    for(ll i = 1; i < n; i++) {
        ll to;
        cin >> to;
        dp[0][i] = max({dp[1][i - 1], dp[2][i - 1], dp[0][i - 1]});
        if(to == 1 || to == 3) {
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + 1;
        }
        if(to == 2 || to == 3) {
            dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + 1;
        }
    }
    cout << n - max({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << '\n';
}
