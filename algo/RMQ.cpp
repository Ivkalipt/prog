#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

struct Seg_tree {
    vll t;
    ll n;

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize(2 * n - 1, 0);
    }

    void build(vll & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vll & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = a[lx];
            return;
        }
        else if(rx - lx != 1) {
            ll m = (lx + rx) / 2, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
            t[v] = t[v1] + t[v2];
        }
    }

    void set(ll i, ll x) {
        set(i, x, 0, 0, n);
    }

    void set(ll i, ll x, ll v, ll lx, ll rx) {
        if(rx - lx == 1) {
            t[v] = x;
            return;
        }
        ll m = (lx + rx) / 2, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        if(m > i) set(i, x, v1, lx, m);
        else set(i, x, v2, m, rx);
        t[v] = t[v1] + t[v2];
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, n);
    }

    ll sum(ll l, ll r, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && r >= rx) return t[v];
        ll m = (lx + rx) / 2, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        return sum(l, r, v1, lx, m) + sum(l, r, v2, m, rx);
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for(ll & c : a) cin >> c;
    Seg_tree t;
    t.build(a);
    while(m--) {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if(t1 - 1) cout << t.sum(t2, t3) << '\n';
        else t.set(t2, t3);
    }
}
