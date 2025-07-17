#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

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

void path(ll i, ll n, vll & dp, vll & c) {
    if(i == 0) return;
    for(ll j = 0; j < n; j++) {
        if(dp[i - c[j]] + 1 == dp[i] && i >= c[j]) {
            path(i - c[j], n, dp, c);
            cout << c[j] << ' ';
            break;
        }
    }
}

int main() {
    ll n, s;
    cin >> n;
    vll c(n);
    for(ll & v : c) cin >> v;
    cin >> s;
    vll dp(s + 1, inf), p(s + 1, -1);
    dp[0] = 0;
    for(ll i = 1; i <= s; i++) {
        for(ll j = 0; j < n; j++) {
            if(i >= c[j] && dp[i - c[j]] + 1 < dp[i]) {
                dp[i] = dp[i - c[j]] + 1;
                p[i] = i - c[j];
            }
        }
    }
    // cout << dp[s] << '\n';
    if(dp[s] == inf) cout << -1 << '\n', exit(0);
    ll ind = s;
    while(p[ind] != -1) {
        cout << ind - p[ind] << ' ';
        ind = p[ind];
    }

    cout << '\n';
}
