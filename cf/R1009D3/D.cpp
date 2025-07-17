#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<long long>;

struct circle {
    ll x, r;
};

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<circle> a(n);
    map<ll, ll> x;
    for(auto & c : a) cin >> c.x;
    for(auto & c : a) cin >> c.r;
    for(auto c : a) {
        ll l = c.x - c.r;
        ll r = c.x + c.r;
        for(ll i = l; i <= r; i++) {
            ll lx = 0, rx = c.r + 1;
            while(rx - lx > 1) {
                ll mid = (lx + rx) / 2;
                if(mid * mid + (c.x - i) * (c.x - i) > c.r * c.r) rx = mid;
                else lx = mid;
            }
            if(!x.count(i) || x[i] < lx) x[i] = lx;
            // cout << i << ' ' << lx << '\n';
        }
        // cout << '\n';
    }
    // cout << '\n';
    ll ans = 0;
    for(auto [y, h] : x) {
        //cout << y << ' ' << h << '\n';
        ans += (h + 1) * 2 - 1;
    }
    cout << ans << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
