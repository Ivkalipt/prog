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

const ll inf = 1e9 + 7;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        bool f = 1;
        cin >> n;
        vector<char> a(n);
        for(char & c : a) cin >> c;
        a.push_back('.');
        vll dp(n + 1, 0);
        dp[1] = (a[1] == '@');
        for(ll i = 2; i < n; i++) {
            if(a[i] == '*' && a[i - 1] == '*') f = 0;
            if(a[i] != '*') dp[i] = max(dp[i - 1], dp[i - 2]) + (a[i] == '@' && f);
        }
        for(ll i = n; i > -1; i--) {
            if(dp[i]) {
                cout << dp[i] << '\n';
                break;
            }
            if(i == 0) cout << 0 << '\n';
        }

    }
}
