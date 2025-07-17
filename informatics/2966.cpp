#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define vstr vector<string>
#define vvll vector<vector<ll>>
#define vvstr vector<vector<string>>
#define bpStart for(ll i = 0; i < n; i++) { for(ll j = 0; j < m; j++) {
#define bpEnd } }


using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vvll costs(n, vll(m, 0)), dp(n, vll(m, 0));
    vvstr way(n, vstr(m, ""));
    bpStart
    cin >> costs[i][j];
    bpEnd
    bpStart
    if(i == 0 && j == 0) {
        dp[i][j] = costs[i][j];
    }
    else if(i == 0) {
        dp[i][j] = dp[i][j-1] + costs[i][j];
        way[i][j] = way[i][j-1] + "R";
    }
    else if(j == 0) {
        dp[i][j] = dp[i-1][j] + costs[i][j];
        way[i][j] = way[i-1][j] + "D";
    }
    else {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + costs[i][j];
        if(dp[i][j-1] > dp[i-1][j]) {
            dp[i][j] = dp[i][j-1] + costs[i][j];
            way[i][j] = way[i][j-1] + "R";
        }
        else {
            dp[i][j] = dp[i-1][j] + costs[i][j];
            way[i][j] = way[i-1][j] + "D";
        }
    }
    bpEnd
    cout << dp[n-1][m-1] << "\n";
    for(auto c:way[n-1][m-1]) {
        cout << c << " ";
    }

    
}