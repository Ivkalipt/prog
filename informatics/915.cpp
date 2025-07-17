#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define F first
#define S second

using namespace std;

int main() {
    ll n, t;
    cin >> n;
    vll costs, dp(n);
    for(ll i = 0; i < n; i++) {
        cin >> t;
        costs.push_back(t);
    }
    costs.push_back(0);
    dp[0] = costs[0];
    dp[1] = costs[1];
    for(ll i = 2; i < n; i++) {
        dp[i] = min(dp[i-1], dp[i-2])+costs[i];
    }
    cout << dp[n-1];
}