#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

int main() {
    ll m;
    cin >> m;
    vector<pll> seg;
    ll l1, r1;
    cin >> l1 >> r1;
    while(l1 || r1) {
        seg.push_back({l1, r1});
        cin >> l1 >> r1;
    }
    seg.push_back({m, m + 1});
    ll n = seg.size();
    sort(all(seg), [&] (pll x, pll y) {return x.F < y.F || (x.F == y.F && x.S < y.S);});
    ll r = 0, rnew = 0, ind = 0;
    vector<pll> ans;
    for(ll i = 0; i < n; i++) {
        if(seg[i].S < 0 || seg[i].F > m) continue;
        if(seg[i].F > r) {
            if(rnew < r) cout << "No solution\n", exit(0);
            r = rnew;
            ans.push_back(seg[ind]);
        }
        if(seg[i].F <= r) {
            if(seg[i].S > rnew) rnew = seg[i].S, ind = i;
        }
    }
    if(r < m) cout << "No solution\n";
    else {
        cout << ans.size() << '\n';
        for(pll c : ans) cout << c.F << ' ' << c.S << '\n';
    }

    return 0;
}

