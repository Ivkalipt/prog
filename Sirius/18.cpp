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
    ios_base::sync_with_stdio(0);
    ll n, m, t;
    cin >> n;
    vll stgh(n), cnt(n);
    for(ll i = 0; i < n; i++) {
        cin >> stgh[i];
    }
    cin >> m;
    for(ll i = 0; i < m; i++) {
        cin >> t;
        ++cnt[t-1];
    }
    for(ll i = 0; i < n; i++) {
        if(stgh[i] < cnt[i]) {
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
    
    cout << "\n";
    return 0;
}