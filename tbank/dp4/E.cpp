#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 405;
ll dp[MAXN][MAXN];
ll prefix[MAXN];

ll rec(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = prefix[r+1] - prefix[l];
    
    ll res = 0;
    for (int k = l; k < r; ++k) {
        ll left = rec(l, k);
        ll right = rec(k+1, r);
        if (left == right) {
            res = max(res, left + right);
        }
    }
    
    for (int k = l; k < r; ++k) {
        for (int m = k+1; m < r; ++m) {
            ll left = rec(l, k);
            ll middle = rec(k+1, m);
            ll right = rec(m+1, r);
            if (left == right) {
                res = max(res, left + middle + right);
            }
        }
    }
    
    return dp[l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    
    memset(dp, -1, sizeof(dp));
    prefix[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix[i+1] = prefix[i] + a[i];
        dp[i][i] = a[i];
    }
    
    rec(0, n-1);
    
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
