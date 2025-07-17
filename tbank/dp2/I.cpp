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
    ll s, cnt = 0;
    cin >> s;
    ll a, b, c;
    cin >> a >> b >> c;
    vector<bool> dp(s + 1, 0);
    dp[1] = 1;
    for(ll i = 1; i <= s; i++) {
        if(i + b <= s && dp[i])
            dp[i + b] = 1;
        if(i + a <= s && dp[i])
            dp[i + a] = 1;
        if(i + c <= s && dp[i])
            dp[i + c] = 1;
    }
    for(bool c : dp) cnt += (c ? 1 : 0);
    cout << cnt << '\n';

}
