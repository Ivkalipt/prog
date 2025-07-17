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

const ll maxn = 401, inf = 1e18;

ll dp[maxn][maxn], sz[maxn][maxn], a[maxn];

ll rec(ll l, ll r) {
    if(dp[l][r] != inf) return dp[l][r];
    if(l == r) dp[l][r] = 0;
    if(l + 1 == r) dp[l][r] = a[l] + a[r];
    for(ll k = l; k < r; k++) {
        dp[l][r] = min(rec(l, k) + rec(k + 1, r) + sz[l][r], dp[l][r]);   
    }
    return dp[l][r];
}

int main() {
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = inf;
            for(ll k = i; k <= j; k++) {
                sz[i][j] += a[k];
            }
        }
    }
    /*for(ll d = 1; d < n; d++) {
        for(ll l = 0; l + d < n; l++) {
            ll r = l + d;
            for(ll k = l; k <= r; k++) {
                dp[l][r] = min(dp[l][k], dp[k + 1][r]);
            }
        }
    }*/
    cout << rec(0, n - 1) << '\n';
    /*for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/

}
