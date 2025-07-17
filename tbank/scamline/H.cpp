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

struct ev {
    ll cord, type, ind;
};

pll stupid(ll n, vector<pll> & segs) {
    ll maxs = inf, maxi, maxj;
    for(ll i = 0; i < n - 1; i++) {
        for(ll j = i + 1; j < n; j++) {
            if(segs[i].F <= segs[j].F && segs[j].F <= segs[i].S) {
                if(maxs > segs[i].S - segs[j].F && segs[i].S - segs[j].F != 0) maxs = segs[i].S - segs[j].F, maxi = i, maxj = j;
            }
            else if(segs[j].F <= segs[i].F && segs[i].F <= segs[j].S) {
                if(maxs > segs[j].S - segs[i].F && segs[j].S - segs[i].F != 0) maxs = segs[j].S - segs[i].F, maxi = i, maxj = j;
            }
        }
    }
    // cout << maxs << '\n';
    if(maxs != inf)
        return {maxi + 1, maxj + 1};
    return {0, 0};
}

void coutup(vll a) {
    for(ll c : a) cout << c << ' ';
    cout << '\n';
} 

int main() {
    ll n;
    cin >> n;
    vector<ev> a;
    vector<pll> segs(n);
    bool f = 0;
    for(ll i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        a.push_back({l, 0, i});
        a.push_back({r, 1, i});
        segs[i] = {l, r};
    }
    sort(all(a), [&] (ev x, ev y) {
            return x.cord < y.cord || (x.cord == y.cord && x.type > y.type);
            });
    // for(ev c : a) cout << '{' << c.cord << ' ' << c.type << ' ' << c.ind << ' ' << "} ";
    ll cnt = 0, maxs = inf, toi, maxi, maxj, start = -1;
    for(ll i = 0; i < 2 * n; i++) {
        if(a[i].type == 1) {
            cnt--;
            if(maxs > a[i].cord - start && a[i].ind != toi) maxs = a[i].cord - start, maxj = a[i].ind, maxi = toi, f = 1;
            
        }
        else {
            cnt++;
            start = a[i].cord;
            toi = a[i].ind;
        }
        // coutup({maxs, maxi, maxj, start, toi});
    }
    //if(!f) cout << 0 << '\n';
    //else cout << maxi + 1 << ' ' << maxj + 1 << '\n';
    pll ans = stupid(n, segs);
    if(ans.F == 0) cout << 0 << '\n';
    else cout << ans.F << ' ' << ans.S << '\n';
} 
