// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 

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
    cout << 2*dp1[n-1] + dp2[n-1] << '\n';

}
