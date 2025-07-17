// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

int main() {
    ll n; 
    cin >> n;
    vvll a(4, vll(n));
    vll cnt(n), dp(n+3);
    for(ll i = n-1; i >= 0; i--) {
        cin >> a[1][i] >> a[2][i] >> a[3][i];
    }
    dp[0] = a[1][0];
    dp[1] = min(a[2][1], a[1][0] + a[1][1]);
    dp[2] = min(min(a[3][2], a[1][0]+a[2][2]), min(a[1][0]+a[1][1]+a[1][2], a[2][1]+a[3][2]));
    for(ll i = 3; i < n; i++) {
        dp[i] = min(dp[i-1]+a[1][i], min(dp[i-3]+a[3][i], dp[i-2]+a[2][i]));
        /*switch(cnt[i-1]) {
            case 1:
                if(a+a[1][i] > a[2][i]) {
                    dp[i] = dp[i-1] + a[1][i];
                    cnt[i] = 1;
                }
                else {
                    dp[i] = a[2][i];
                    cnt[i] = 2;
                }
                break;
            case 2:
                if(dp[i-1] + a[1][i])
        }
        
        if(cnt[i-1] == 3) {
            dp[i] = dp[i-1] pass;
        } 
        else {
            if(a[cnt][i-1] + a[1][i] > a[cnt+1][i]) {
                dp[i] = 
            }
        }*/
    }
    cout << dp[n-1];
}