// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>

using namespace std;

int main() {
    ll n, t;
    cin >> n;
    vll dp1(n), dp2(n);
    dp1[0] = 1; dp2[0] = 1;
    for(ll i = 1; i < n; i++) {
        dp1[i] = dp1[i-1]*2 + dp2[i-1];
        dp2[i] = dp1[i]-dp2[i-1]; 
    }
    cout << 2*dp1[n-1] + dp2[n-1];

}