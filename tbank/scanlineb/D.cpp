#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
    ll n;
    ll cont = 86400;
    cin >> n;
    vector<pll> segs;
    for(ll i = 0; i < n; i++) {
        ll to, tc, h, m, s;
        cin >> h >> m >> s;
        to = h * 3600 + m * 60 + s;
        cin >> h >> m >> s;
        tc = h * 3600 + m * 60 + s;
        if(to >= tc) {
            segs.push_back({cont, 1});
            segs.push_back({0, 0});
            if(to == tc) continue;
        }
        segs.push_back({tc, 1});
        segs.push_back({to, 0});
    }
    sort(all(segs), [&] (pll x, pll y) {
            return (x.F < y.F || (x.F == y.F && x.S < y.S));
            });
    ll cnt = 0;
    ll start = 0;
    // bool f = 0;
    // for(pll c : segs) cout << '(' << c.F << ',' << c.S << ") ";
    ll ans = 0;
    for(ll i = 0; i < segs.size(); i++) {
        if(segs[i].S == 0) {
            cnt++;
            start = segs[i].F;
        }
        if(segs[i].S == 1) {
            if(cnt == n) ans += segs[i].F - start;
            cnt--;
        }
        // cout << cnt << '\n';
    }
    cout << ans << '\n';
    
}
