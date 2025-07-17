// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

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

const ll inf = 1e9 + 7;

ll countHeight(vll &a, ll w) {
    ll w1 = w;
    ll h = 0;
    for(ll i = 0; i < a.size(); i++) {
        if(a[i] > w) return inf;
        if(a[i] > w1) {
            w1 = w - a[i];
            h++;
            continue;
        }
        w1 -= a[i];
        if(a[i]) w1--;
    }
    return h + 1;
}

int main() {
    ll w, n, m;
    cin >> w >> n >> m;
    vector<ll> a(n, 0), b(m, 0);
    for(ll &c : a) cin >> c;  
    for(ll &c : b) cin >> c;
    ll l1 = 0, r1 = max(a.size(), b.size()); 
    while(r1 - l1 > 1) {
        ll y = (l1 + r1) / 2;
        ll l = 0, r = w;
        while(r - l > 1) {
            ll m = (l + r) / 2;
            if(countHeight(a, m) >= y) {
                r = m;
            }
            else {
                l = m;
            }
            cout << countHeight(a, m) << ' ';
        }
        cout << '\n';
        ll x0 = r;
        l = 0;
        r = w;
        while(r - l > 1) {
            ll m = (l + r) / 2;
            if(countHeight(b, w - m) >= y) {
                r = m;
            }
            else {
                l = m;
            }
            cout << countHeight(b, w - m) << ' ';
        }
        cout << '\n';
        ll x1 = r;
        if(x1 > x0) {
            l1 = m;
        }
        else {
            r1 = m;
        }
    }
    cout << r1 << '\n';


}
