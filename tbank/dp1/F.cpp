// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>
#include <string>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define f first
#define s second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
    ll n;
    cin >> n;
    vll dp(n + 1, 0);
    vector<string> way(n + 1, "");
    for(ll i = 1; i <= n; i++) {
        ll c = dp[i - 1];
        bool f = 1;
        if(i % 2 == 0) {
            c = min(c, dp[i / 2]);
            if(c == dp[i / 2]) {
                way[i] = way[i / 2] + (i == 1 ? "" : " ") + to_string(i);
                f = 0;
            }
        }
        if(i % 3 == 0) {
            c = min(c, dp[i / 3]);
            if(c == dp[i / 3]) {
                way[i] = way[i / 3] + (i == 1 ? "" : " ") + to_string(i);
                f = 0;
            }
        }
        dp[i] = c + 1;
        if(f) way[i] = way[i - 1] + (i == 1 ? "" : " ") + to_string(i);
    }
    cout << dp[n] - 1 << '\n' << way[n] << '\n';
}
