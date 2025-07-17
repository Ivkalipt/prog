#pragma GCC optimize ("O3,unroll-loops")
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

struct dot {
    ll x, type, ind;
};

struct now {
    ll l, r, ind;
};

bool operator < (const now & x, const now & y) {
    return x.r > y.r;
}


int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    ll m;
    cin >> m;
    vector<bool> nusd(n);
    vector<pll> segs(m);
    vector<dot> scan;
    for(ll i = 0; i < n; i++) scan.push_back({i, 1});
    for(ll i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        scan.push_back({l, 0, i});
        scan.push_back({r, 2, i});
        segs[i] = {l, r};
    }
    sort(all(scan), [&] (dot x, dot y) {
            return (x.x < y.x || (x.x == y.x && x.type < y.type));
            });
    for(dot c : scan) cout << c.x << ' ' << c.type << ' ' << c.ind << "| ";
    cout << '\n';
    ll cnt = 0, ans = 0;
    set<now> t;
    for(ll i = 0; i < scan.size(); i++) {
        ll ind = scan[i].ind;
        if(scan[i].type == 0) cnt++, t.insert({segs[ind].F, segs[ind].S, ind});
        if(scan[i].type == 1) {
            while(a[i] < cnt) {
                t.erase(*t.begin());
                cout << cnt << '\n';
                ans++, cnt--;
            }
        }
        if(scan[i].type == 2 && t.count({segs[ind].F, segs[ind].S, ind})) cnt--, t.erase({segs[ind].F, segs[ind].S, ind});
        for(now c : t) cout << c.l << ' ' << c.r << ' ' << c.ind << "| ";
        cout << '\n';
    }


    cout << ans << '\n';

}
