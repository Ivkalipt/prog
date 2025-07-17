#include <algorithm>
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

int main() {
    ll n;
    cin >> n;
    vector<ev> a;
    for(ll i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        a.push_back({l, 0, i});
        a.push_back({r, 1, i});
    }
    sort(all(a), [&] (ev x, ev y) {
            return x.cord < y.cord || (x.cord == y.cord && x.type < y.type);
            });
    map<ll, ll> act;
    ll ans = inf, maxi = -1, maxj = -1;
    unordered_map<ll, ll> indexes;
    for(ll i = 0; i < 2 * n; i++) {
        ll cord = a[i].cord;
        if(a[i].type == 0) {
            if(act.count(cord)) act[cord]++;
            else act[cord] = 1;
            indexes[cord] = a[i].ind;
        }
        else {
            auto iter = act.end();
            --iter;
            if(iter->F == cord) {
                if(act.size() > 1) {
                    --iter;
                    if(ans > cord - iter->F) ans = cord - iter->F, maxi = a[i].ind, maxj = indexes[iter->F];    
                }
            }
            else {
                if(ans > cord - iter->F) ans = cord - iter->F, maxi = a[i].ind, maxj = indexes[iter->F];    
            }
            act[iter->F]--;
            if(act[iter->F] == 0) act.erase(iter->F);
        }
    }
    if(maxi == maxj) cout << 0 << '\n';
    else cout << maxi + 1 << ' ' << maxj + 1 << '\n';

}
