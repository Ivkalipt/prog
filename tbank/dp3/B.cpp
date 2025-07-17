#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

ll dp[83][11];

int main() {
    ll s;
    cin >> s;
    for(ll i = 0; i <= 9; i++) dp[1][i] = 1;
    cout << dp[10][1] << '\n';
    for(ll i = 0; i <= 9; i++) dp[1][i] = 1;
    for(ll i = 1; i <= 9; i++) {
        for(ll j = 1; j <= s; j++) {
            for(ll k = 1; k <= j; k++) {
                dp[j][i] += dp[k][i - 1];
            }
        }
    }    
    ll ans = 0;
    for(ll j = 1; j <= 9; j++) {
        ans += dp[s][j];
        cout << ans << ' ';
    }
    cout << ans  << '\n';
}
