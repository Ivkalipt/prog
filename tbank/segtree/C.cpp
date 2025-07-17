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

struct SegTree {
    ll n;
    vll a, t;

    ll cmp(ll x, ll y) {
        return gcd(x, y);
    }
    
    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize(2 * n - 1, 0);
    }

    void build(vll & arr) {
        a = arr;
        resize(a.size());
        build(0, 0, n);
    }

    void build(ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = a[lx];
            return;
        }
        else if(rx - lx != 1) {
            ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
            build(v1, lx, m);
            build(v2, m, rx);
            t[v] = cmp(t[v1], t[v2]);
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
        ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
        if(m > i) set(i, x, v1, lx, m);
        else set(i, x, v2, m, rx);
        t[v] = cmp(t[v1], t[v2]);
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, n);
    }

    ll get(ll l, ll r, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && r >= rx) return t[v];
        ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
        return cmp(get(l, r, v1, lx, m), get(l, r, v2, m, rx));
    }
};

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    SegTree t;
    t.build(a);
    // for(ll c : t.t) cout << c << ' ';
    ll q;
    cin >> q;
    while(q--) {
        char tp;
        cin >> tp;
        if(tp == 's') {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << t.get(l, r) << '\n';
        }
        else {
            ll i, v;
            cin >> i >> v;
            i--;
            t.set(i, v);
        }
    }
}
