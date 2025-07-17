//Гвоздики
// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

int main() {
    ll n;
    cin >> n;
    vll a(n), dp(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    dp[1] = a[1] - a[0];
    dp[2] = a[2] - a[0];
    for(ll i = 3; i < n; i++) {
        dp[i] = min(dp[i-1], dp[i-2]) + (a[i] - a[i-1]);
    }
    cout << dp[n-1];
}