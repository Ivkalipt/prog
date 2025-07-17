// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

int main() {
    fastio;
    ll n, t1, t2;
    cin >> n;
    vpll a;
    for(ll i = 0; i < n; i++) {
        cin >> t1;
        a.push_back({t1, i});
    }
    sort(a.begin(), a.end(), [](pair<ll, ll> a,  pair<ll, ll> b) {
        return a.F > b.F;
    });
    
    cout << "\n";
    return 0;
}