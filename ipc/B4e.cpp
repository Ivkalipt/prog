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
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

int main() {
    fastio;
    ll n, cnt=0, t1, t2, maxi = -10e6;
    cin >> n;
    vll s1(n), s2(n);
    vector<pair<ll, ll>> a;
    for(ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        a.push_back({t1, 0});
        a.push_back({t1+t2, 1});
    }
    sort(a.begin(), a.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
        return (a.F < b.F || (a.F == b.F && a.S > b.S));
    });
    /*for(auto c:a) {
        cout << c.F << " " << c.S << "\n";
    }*/
    for(auto c:a) {
        // cout << c.F << ' ' << c.S << '\n';
        if(c.S == 0) {
            cnt++;
            if(cnt > maxi) {
                maxi = cnt;
            }
        }
        else {
            cnt--;
        }
    }
    cout << maxi;
    cout << "\n";
    return 0;
}