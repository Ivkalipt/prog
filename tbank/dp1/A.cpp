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
    ll n;
    cin >> n;
    vll dp(n + 1, 1);
    for(ll i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << '\n';
}
