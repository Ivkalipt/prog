#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<long long>;

ll inf = 1e16;

void solve() {
    ll n;
    cin >> n;
    vector<pll> a(n);
    for(pll & c : a) cin >> c.F;
    for(pll & c : a) cin >> c.S;
    sort(all(a), [&] (pll x, pll y) {
            return x.S - x.F < y.S - y.F;
            });
    ll l = 0, r = n - 1, cnt = 0;
    while(r - l > 0) {
        if(a[l].F + a[r].F <= a[l].S + a[r].S) {
            cnt++;
            l++;
            r--;
        }
        else l++;
    }
    cout << cnt << '\n';
}
int main() {
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
