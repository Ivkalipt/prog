// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

const ll inf = 1e9 + 7;

int main () {
    ll k, n;
    cin >> k >> n;
    vll dp(n + 2, 0), s(n + 2, 0);
    dp[1] = 1;
    s[1] = 1;
    for(ll i = 2; i <= n + 1; i++) {
        dp[i] = (s[i - 1] - s[max((ll)1, i - k) - 1]) % inf;
        s[i] = s[i - 1] + dp[i];

    }
    cout << dp[n + 1] << '\n';
}
