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
    ll n;
    cin >> n;
    vll a(n+3), dp1(n+3), dp2(n+3), dp3(n+3);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp1[0] = a[0];
    dp1[1] = a[0]+a[1];
    dp1[2] = a[0]+a[1]+a[2];
    dp2[1] = a[0]*a[1];
    dp2[2] = a[0]*a[1]+a[0]*a[2]+a[1]*a[2];
    dp3[2] = a[0]*a[1]*a[2];
    for(ll i = 1; i < n; i++) {
        dp1[i] = dp1[i-1]+a[i];
        dp2[i] = dp2[i-1]+a[i]*dp1[i-1];
        dp3[i] = dp3[i-1]+a[i]*dp2[i-1];
    }
    cout << dp3[n-1];
    cout << "\n";
    return 0;
}