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

void searchD(vvll & dp, ll l, ll r, ll n) {
   while(l < n && -1 < r) {
        dp[l][r] += (l < n && r > 1 ? dp[l + 1][r - 2] : 0) 
                 + (l > 1 ? dp[l - 2][r + 1] : 0)
                 + (l > 1 && r > 0 ? dp[l - 2][r - 1] : 0)
                 + (l > 0 && r > 1 ? dp[l - 1][r - 2] : 0);
        l++, r--;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vvll dp(n + 1, vll(m + 1, 0));
    dp[0][0] = 1;
    for(ll r = 0; r < m; r++) searchD(dp, 0, r, n);
    for(ll l = 1; l < n; l++) searchD(dp, l, m - 1, n);
    cout << dp[n - 1][m - 1];
}
