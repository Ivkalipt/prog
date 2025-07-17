// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
//#define vll  vector<ll>
//#define vvll vector<vector<ll>>
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

int main() {
    ll n, t1, t2;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        a[i] = {t1, t2};
    }
    for(ll i = 0; i < n-1; i++) {
        for(ll j = i+1; j < n; j++) {
            if(a[i].S < a[j].S) {
                swap(a[i], a[j]);
            }
            else if(a[i].S == a[j].S) {
                if(a[i].F > a[j].F) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
    for(auto c:a) {
        cout << c.F << ' ' << c.S << "\n";
    }

}