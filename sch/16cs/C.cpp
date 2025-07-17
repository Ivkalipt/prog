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

int main() {
    string s;
    getline(cin, s);
    ll n = s.size();
    ll mx = 0,  cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(s[i] == ' ') cnt++;
        else cnt = 0;
        if(cnt > mx) mx = cnt;
    }
    cout << mx << '\n';
}
