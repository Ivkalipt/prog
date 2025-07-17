#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll maxn = 4e2 + 2, inf = 1e18;

ll p[maxn], a[maxn];
bool dp[maxn][maxn];

ll rec(ll l, ll r) {
    if(dp[l][r] != 0) dp[l][r] = dp[l][r];
    else if(l == r) dp[l][r] = a[l];
    else {
        for(ll k = l; k < r; k++)
            if(rec(l, k) == rec(k + 1, r)) dp[l][r] = max(dp[l][r], rec(l, k) + rec(k + 1, r));
        for(ll k = l; k < r; k++) {
            for(ll m = k + 1; m < r; m++) {
                if(rec(l, k) == rec(m + 1, r)) dp[l][r] = max(dp[l][r], rec(l, k) + rec(k + 1, m) + rec(m + 1, r));
            }
        }
    }
    return dp[l][r];
}

int main() {
    for(ll i = 1; i < maxn; i++) dp[i][i] = true;
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
    
    cout << ans << '\n';
}
