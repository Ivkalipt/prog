#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

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

int main() {
    ll n, sum = 0;
    cin >> n;
    vll m(n);
    for(ll & c : m) {
        cin >> c;
        sum += c;
    }
    if(sum & 1) cout << "NO\n", exit(0);
    ll W = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(W + 1, 0));
    dp[0][0] = true;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if(m[i - 1] <= j && dp[i - 1][j - m[i - 1]]) dp[i][j] = true;
        }
    }
    if(dp[n][W]) cout << "YES\n";
    else cout << "NO\n";

}
