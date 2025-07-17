// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

int main() {
    ll n, q, t;
    cin >> n >> q;
    vll a(n);
    for(ll &c : a) cin >> c;
    sort(all(a));
    for(ll i = 0; i < q; i++) {
        cin >> t;
        ll l = -1;
        ll r = n - 1;
        while(r - l > 1) {
            ll m = (r + l) / 2;
            if(a[m] < t) l = m;
            else r = m;
        }
        if(a[r] == t) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
