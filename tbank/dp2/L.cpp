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
    ll n, m;
    cin >> n >> m;
    vpll a(n + 1);
    for(ll i = 1; i <= n; i++) cin >> a[i].F >> a[i].S;
    vll prefL(n + 1);
    for(ll i = 1; i <= n; i++) prefL[i] = prefL[i - 1] + a[i].F;
    // for(ll i = 0; i <= n; i++) cout << prefL[i] << ' ';
    cout << '\n';
    vvll s(n + 1, vll(n + 1, 0));
    for(ll i = 1; i < n; i++) {
        for(ll j = i + 1; j <= n; j++) {
            s[i][j] = s[i][j - 1] + (prefL[j - 1] - prefL[i - 1]) * a[j].S;
        }
    }
    /*for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= n; j++) {
            cout << s[i][j] << ' ';
        }
        cout << '\n';
    }*/
    vvll dp(m + 1, vll(n + 1, inf));
    for(ll i = 0; i <= m; i++) dp[i][i] = 0;
    for(ll i = 1; i <= m; i++) {
        for(ll j = i; j <= n; j++) {
            dp[i][j] = dp[i - 1][0] + s[1][j];
            for(ll k = 2; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + s[k][j]);
                // cout << dp[i][j] << ' ' << dp[i - 1][k - 1] + s[k][j] << '\n';
            }
        }
    }
    /*for(ll i = 0; i <= m; i++) {
        for(ll j = 0; j <= n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << dp[m][n] << '\n';

}
