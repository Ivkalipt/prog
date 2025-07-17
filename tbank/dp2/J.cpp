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

const ll inf = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vvll dp(n, vll(n, 0));
    for(ll i = 0; i < n; i++) {
        dp[i][i] = 0;
        dp[i][min(i + 1, n - 1)] = (s[i] != s[min(i + 1, n - 1)]);
    }

    for(ll d = 3; d <= n; d++) {
        for(ll l = 0, r = l + d - 1; r < n; r++, l++) {
            dp[l][r] = (s[l] != s[r]) + dp[l + 1][r - 1];
        }
    }
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i; j < n; j++) {
            if(dp[i][j] <= k) cnt++;
        }
    }
    cout << cnt << '\n';
}
