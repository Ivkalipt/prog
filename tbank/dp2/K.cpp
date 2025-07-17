#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e16;

int main() {
    ll n, m;
    cin >> n;
    vll a(n + 1);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    vll b(m + 1);
    for(ll i = 1; i <= m; i++) cin >> b[i];
    vvll dp(n + 1, vll(m + 1, 0));
    vll p(m + 1, LLONG_MIN);
    for (ll i = 1; i <= n; i++) {
        ll ind = 0;
        ll val = 0; 
        for (ll j = 1; j <= m; j++) {	
            dp[i][j] = dp[i - 1][j]; 
            if (a[i] == b[j] && dp[i - 1][j] < val + 1) {
                dp[i][j] = val + 1;
                p[j] = ind;
            }
            if (a[i] > b[j] && dp[i - 1][j] > val) {
                val = dp[i - 1][j];
                ind = j;
            }
        }
    }
    ll ind = 1;
    for(ll j = 1; j <= m; j++)
        if (dp[n][ind] < dp[n][j])
            ind = j;

    vll ans;
    while(p[ind] != LLONG_MIN) {
        ans.push_back(b[ind]);
        ind = p[ind];
    }
    // ans.pop_back();
    reverse(all(ans));
    cout << ans.size() << '\n';
    for(ll c : ans) cout << c << ' ';
}
    /*vll p(n + m + 2, -1);
    vvll dp(n + 1, vll(m + 1, 0));
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = 1;
                for(ll k = 1; k < i; k++) {
                    if(a[k] < a[i] && dp[i][j] < dp[k][j] + 1) {
                        dp[i][j] = dp[k][j] + 1;
                        p[i] = k;
                    }
                }
            }
            else dp[i][j] = dp[i][j - 1];
        }
    }
    ll ind = 1;
    for(ll i = 1; i <= n; i++) {
        if(dp[ind][m] < dp[i][m]) ind = i;
    }
    vll path;
    while(ind + 1 != -1) {
        path.push_back(p[ind + 1]);
        ind = p[ind + 1];
    }
    for(ll c : p) cout << c << ' ';
    cout << '\n';
    cout << path.size() << '\n';
    reverse(all(path));
    for(ll c : path) {
        cout << c << ' ';
    }
    cout << '\n';


}*/
