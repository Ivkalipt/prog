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
    ll n, m, lx, s, mid;
    cin >> n >> m;
    vll a(n), pref(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    pref[0] = 0;
    for(ll i = 1; i <= n; i++) {
        pref[i] = a[i-1] + pref[i-1];
    }
    // for(auto c:a) {
    //     // cout << c << " ";
    // }
    // cout << "\n";
    // for(auto c:pref) {
    //     // cout << c << " ";
    // }
    // cout << "\n";
    for(ll i = 0; i < m; i++) {
        cin >> lx >> s;
        ll l = 1, r = n;
        while(r-l > 1) {
            mid = (l+r)/2;
            if(pref[mid]-pref[mid-lx] >= s) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        // cout << r << ' ' << l << '\n';
        if (pref[r] - pref[r-lx] == s) {
            cout << r - lx + 1;
        }
        else if (pref[l] - pref[l-lx] == s) {
            cout << l - lx + 1;
        }
        else {
            cout << -1;
        }
        cout << "\n";

    }
    return 0;
}