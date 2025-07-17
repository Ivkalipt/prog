// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define F first
#define S second

using namespace std;

int main() {
    fastio;
    ll cnt = 0, n;
    string s2, s = "";
    cin >> s2;
    for(auto c:s2) {
        if(c == 'B') cnt++;
        else s += c;
    }
    n = s.size();
    vll dpr(n+1, 1e5+1), dpl(n+1, 1e5+1);
    dpr[0] = 1; dpl[0] = 0;
    for(ll i = 1; i < n; i++) {
        dpr[i] = min(dpr[i-1]+(s[i-1]=='R'), dpl[i-1]+1);
        dpl[i] = min(dpl[i-1]+(s[i-1]=='L'), dpr[i-1]+1);
    }
    cout << dpr[n] + cnt;

    // for(auto c:dpr) {
        // cout << c << " ";
    // }
    return 0;
}