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

ll inf = 1e9 + 7;

void solve() {
    ll n, cnt = 0;
    string s;
    cin >> n >> s;
    if(s[0] == '1') {
        cnt++;
    }
    for(ll i = 1; i < n; i++) {
        if(s[i] != s[i - 1]) cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
