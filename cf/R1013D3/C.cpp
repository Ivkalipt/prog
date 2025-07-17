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
#define rall(a) a.rbegin(), a.rend()

void solve() {
    ll n;
    cin >> n;
    if(n % 2 == 0) cout << -1 << '\n';
    else {
        vll ans;
        for(ll i = 1; i <= n; i++) {
            if(i % 2 == 1) ans.push_back(i); 
        }
        for(ll i = 1; i <= n; i++) {
            if(i % 2 == 0) ans.push_back(i); 
        }
        for(ll c : ans) cout << c << ' ';
        cout << '\n';
    } 
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
