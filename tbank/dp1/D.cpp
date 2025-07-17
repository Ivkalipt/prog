// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    vvll dp(m, vll(n, 0));
    for (ll i1 = 0; i1 < m; i1++) {
        for (ll j1 = 0; j1 < n; j1++) {
            dp[i1].push_back(0);
        }
    }
    dp[0][0] = 1;
    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            if (i - 1 >= 0 && j - 2 >= 0) {
                dp[i][j] += dp[i - 1][j - 2];
            }
            if (i - 2 >= 0 && j - 1 >= 0) {
                dp[i][j] += dp[i - 2][j - 1];
            }
        }
    }
    cout << dp[m - 1][n - 1];
    return 0;
}
