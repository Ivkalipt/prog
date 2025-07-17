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

const ll inf = 1e18, nnum = 10, mod = 1e9 + 7, maxn = 105;

ll dp[maxn][nnum][nnum];

ll f(string & x) {
    ll n = x.size();
    ll ans = 0;
    ll p = 0;
    for(ll i = 0; i < n; i++) {
        ll num = x[i] - '0';
        if(p > num) break;
        for(ll j = p; j < num; j++) {
            for(ll k = 0; k < nnum; k++) {
                ans += dp[n - i][j][k];
                ans %= mod;
            }
        }
        p = x[i] - '0';
    }
    return ans;
}

int main() {
    string l, r;
    cin >> l >> r;
    ll nl = l.size(), nr = r.size();
    for(ll i = 0; i < nnum; i++) dp[1][i][i] = 1;
    for(ll len = 2; len <= maxn; len++) {
        for(ll i = 0; i < nnum; i++) {
            for(ll j = 0; j < nnum; j++) {
                if(i > j) continue;
                for(ll k = i; k <= j; k++) {
                    dp[len][i][j] += dp[len - 1][i][k];
                    dp[len][i][j] %= mod;
                }
            }
        }
    }
    /*for(ll i = 1; i <= nr; i++) {
        for(ll j = 0; j < nnum; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/
    ll fl = 1;
    for(ll i = 1; i < r.size(); i++) {
        if(r[i] < r[i - 1]) fl = 0;
    }
    cout << (((f(r) - f(l)) % mod + mod) % mod + fl) % mod << '\n';
    return 0;
}
