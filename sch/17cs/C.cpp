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

const ll maxn = 101, inf = 1e18;

ll a[maxn][maxn], s[maxn][maxn];

int main() {
    ll n, m;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++) {
            cin >> a[i][j];
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    ll ans = -inf;
    for(ll i1 = 1; i1 <= n; i1++) {
        for(ll j1 = 1; j1 <= m; j1++) {
            for(ll i2 = i1; i2 <= n; i2++) {
                for(ll j2 = j1; j2 <= m; j2++) {
                    ans = max(ans, s[i2][j2] - s[i2][j1 - 1] - s[i1 - 1][j2] + s[i1 - 1][j1 - 1]);
                }
            }
        }
    }
    cout << ans << '\n';

}
