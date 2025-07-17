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
    ll cord, type;
};

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ev> a;
    for(ll i = 0; i < n; i++) {
        ll s, f;
        cin >> s >> f;
        a.push_back({s, 0});
        a.push_back({f, 1});
    }
    sort(all(a), [&] (ev x, ev y) {
            return x.cord < y.cord || (x.cord == y.cord && x.type > y.type);
            });
    ll ans = 0, cnt = 0;
    for(ll i = 0; i < 2 * n; i++) {
        ev c = a[i];
        if(c.type == 0) {
            cnt++;
            if(cnt <= k) {
                ans++;
                //cout << a[i].cord << ' ' << a[i].type << ' ' << ans << '\n';
            }
        }
        if(c.type == 1) {
            cnt--;
        }
        // cout << cnt << '\n';
    }
    cout << ans << '\n';
}
