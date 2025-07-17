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
    ll n, m;
    cin >> n >> m;
    vvll a(n, vll(m, 0)), dp(n, vll(m, 0));
    vector<vector<string>> way(n, vector<string>(m, ""));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(i == 0 && j == 0)
                dp[i][j] = a[i][j];
            else if(i == 0) {
                dp[i][j] = dp[i][j - 1] + a[i][j];
                way[i][j] = way[i][j - 1] + "R"; 
            }
            else if(j == 0) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
                way[i][j] = way[i - 1][j] + "D";
            }
            else {
                if(dp[i][j - 1] > dp[i - 1][j]) {
                    dp[i][j] = dp[i][j - 1] + a[i][j];
                    if(dp[i][j - 1] != 0) way[i][j] = way[i][j - 1] + "R";
                }
                else {
                    dp[i][j] = dp[i - 1][j] + a[i][j];
                    if(dp[i - 1][j] != 0) way[i][j] = way[i - 1][j] + "D";
                }
            }
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
    for(ll i = 0; i < way[n - 1][m - 1].size(); i++) {
        if(i + 1 == way[n - 1][m - 1].size()) cout << way[n - 1][m - 1][i] << '\n';
        else cout << way[n - 1][m - 1][i] << ' ';
    }



}
