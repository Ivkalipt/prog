#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll dp1[10] = {0, 1, 1, 1, 1, 1, 1, 1, 0, 1}, dp2[10];
    for(ll i = 1; i < n; i++) {
        dp2[0] = dp1[4] + dp1[6];
        dp2[1] = dp1[6] + dp1[8];
        dp2[2] = dp1[7] + dp1[9];
        dp2[3] = dp1[4] + dp1[8];
        dp2[4] = dp1[9] + dp1[3] + dp1[0];
        dp2[5] = 0;
        dp2[6] = dp1[7] + dp1[1] + dp1[0];
        dp2[7] = dp1[2] + dp1[6];
        dp2[8] = dp1[1] + dp1[3];
        dp2[9] = dp1[2] + dp1[4];
        // for(ll c : dp2) cout << c << ' ';
        // cout << '\n';
        copy(dp2, dp2 + 10, dp1);
    }
    ll s = 0;
    for(ll c : dp1) s += c;
    cout << s;
}
