// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#pragma GCC optimize ("Ofast")

// #define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

void rec(string pref, ll n, ll k) {
    if(pref.size() == n - 1) {
        for(ll i = 0; i < k; i++) {
            cout << pref + (char)('0' + i) << '\n';
        }
    }
    else {        
        for(ll i = 0; i < k; i++) {
            rec(pref + (char)('0' + i), n, k);
        }
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    rec("", n, k);
}
