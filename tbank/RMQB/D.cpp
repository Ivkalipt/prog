#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

bool f = 0;

struct node {
    ll seg, pref, suf, sz;
};

struct Seg_tree {

    vector<node> t;
    ll n;

    node comb(node a, node b) {
        node res;
        res.seg = max({a.seg, b.seg, a.suf + b.pref});
        if(a.pref == 0) res.pref = 0;
        else if(a.pref == a.sz) res.pref = a.pref + b.pref;
        else res.pref = a.pref;
        if(b.suf == 0) res.suf = 0;
        else if(b.suf == b.sz) res.suf = b.suf + a.suf;
        else res.suf = b.suf;
        res.sz = a.sz + b.sz;
        return res;
    }

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize(2 * n - 1, {0, 0, 0, 0});
    }

    void build(vll & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    node one(ll x) {
        ll el = (x ? 0 : 1);
        return {el, el, el, 1};
    }

    void build(vll & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = one(a[lx]);
            return;
        }
        else if(rx - lx != 1) {
            ll m = (lx + rx) / 2, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
            t[v] = comb(t[v1], t[v2]);
        }
    }

    void set(ll i, ll x) {
        set(i, x, 0, 0, n);
    }

    void set(ll i, ll x, ll v, ll lx, ll rx) {
        if(rx - lx == 1) {
            t[v] = one(x);
            return;
        }
        ll m = (lx + rx) / 2, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        if(m > i) set(i, x, v1, lx, m);
        else set(i, x, v2, m, rx);
        t[v] = comb(t[v1], t[v2]);
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, n).seg;
    }

    node get(ll l, ll r, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return {0, 0, 0, 0};
        if(l <= lx && r >= rx) return t[v];
        ll m = (lx + rx) / 2, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        return comb(get(l, r, v1, lx, m), get(l, r, v2, m, rx));
    }
};

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    Seg_tree t;
    t.build(a);
    ll q;
    cin >> q;
    while(q--) {
        string type;
        cin >> type;
        if(type == "QUERY") {
            ll l, r;
            cin >> l >> r;
            cout << t.get(l - 1, r) << '\n';
        }
        else {
            // for(node c : t.t) cout << c.seg << ' ';
            // cout << '\n';
            ll i, x;
            cin >> i >> x;
            t.set(i - 1, x);
        }
    }
}
