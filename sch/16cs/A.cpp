#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<long long>;

const ll maxn = 510, maxq = 3010;

ld dp[maxn][maxq];

void solve() {
    ll n, q;
    cin >> n >> q;
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= q; j++) {
            for(ll k = 1; k <= 6; k++) {
                if(j - k >= 0) 
                    dp[i][j] += dp[i - 1][j - k] / 6.0;
            }
        }
    }
    /*for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= q; j++) {
            cout << dp[n][q] << ' ';
        }
        cout << '\n';
    }*/

    cout << setprecision(20) << dp[n][q] << '\n';
}

int main() {
    solve();
} 

