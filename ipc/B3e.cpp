// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

bool comp(pair<string, ll> a, pair<string, ll> b) {
    return b.S > a.S;
}

int main() {
    fastio;
    ll n, k, t2;
    string t1;
    cin >> n >> k;
    vector<pair<string, ll>> icq;
    v(string) names;
    for(ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        icq.push_back({t1, t2});
    }
    sort(icq.begin(), icq.end(), comp);
    for(ll i = 0; i < k; i++) {
        names.push_back(icq[i].F);
    }
    sort(names.begin(), names.end());
    for(auto c:names) {
        cout << c << "\n";
    }
    return 0;
}