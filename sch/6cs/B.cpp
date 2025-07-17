#include <algorithm>
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

ll inf = 1e9 + 7;

int main() {
    ll n, l = 0;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    vll dp(n + 1, inf), p(n, -1), pos(n + 1, 0);
    pos[0] = -1;
    dp[0] = -inf;
    for(ll i = 0; i < n; i++) {
        ll j = upper_bound(all(dp), a[i]) - dp.begin();
        if(dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
            pos[j] = i;
            p[i] = pos[j - 1];
            l = max(l, j);
        }
    }
    cout << dp[l] << '\n';
    cout << l << '\n';

}
