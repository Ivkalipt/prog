// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second

using namespace std;

int main() {
    fastio;
    map<char, ll> a;
    ll n, k, s = 0;
    string st;
    
    cin >> n >> k >> st;
    vll dp(n, -10);
    dp[0] = 0;
    a[st[0]] = 0;
    for(ll i = 0; i < n; i++) {
        
    }
    // for(ll i = 0; i < n; i++) {
    //     for(auto c:a) {
    //         if(a.count(st[i])) {
    //             if(i-a[st[i]] <= k) dp[i] = dp[c.S]+(c.F != st[i]);
    //             else dp[i] = min(dp[i], dp[c.S]+(c.F != st[i]));
    //         }
    //     }
    //     a[st[i]] = i;
    // }
    cout << dp[n-1];
    cout << "\n";
    return 0;
}