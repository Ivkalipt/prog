// #pragma GCC optimize ("O3, unroll-all-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    if(n == 1) {
        cout << 0 << '\n';
        return;
    }
    vll nulls;
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(s[i] == '0') cnt++;
        else nulls.push_back(cnt), cnt = 0;
    }
    ll sum = 0;
    for(ll i = 0; i < nulls.size(); i++) {
        sum += nulls[i];
    }
    cout << n - 1 - sum << '\n';
    
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
