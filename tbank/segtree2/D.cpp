#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;

ll inf = 1e16;

struct SegTree {
    struct node {
        ll addv, setv, sum, mn, mx, sz;
    };

    vector<node> t;
    ll n;

    const ll NO = inf;
    const node ZERO_NODE = {0, NO, 0, inf, -inf, 0};

    void push(ll lx, ll rx, ll v) {
        if(rx - lx == 1) return;
        ll v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        if(t[v].setv != NO) {
            t[v1].setv = t[v].setv;
            t[v1].mn = t[v].setv;
            t[v1].mx = t[v].setv;
            t[v1].sum = t[v].setv * t[v1].sz;
            t[v1].addv = 0;

            t[v2].setv = t[v].setv;
            t[v2].mn = t[v].setv;
            t[v2].mx = t[v].setv;
            t[v2].sum = t[v].setv * t[v2].sz;
            t[v2].addv = 0;

            t[v].setv = NO;
        }

        if(t[v].addv != 0) {
            if (t[v1].setv != inf) {
                t[v1].setv += t[v].addv;
                t[v1].sum = t[v1].setv * t[v1].sz;
            } 
            else {
                t[v1].addv += t[v].addv;
                t[v1].sum += t[v].addv * t[v1].sz;
            }
            t[v1].mn += t[v].addv;
            t[v1].mx += t[v].addv;

            if (t[v2].setv != inf) {
                t[v2].setv += t[v].addv;
                t[v2].sum = t[v2].setv * t[v2].sz;
            } 
            else {
                t[v2].addv += t[v].addv;
                t[v2].sum += t[v].addv * t[v2].sz;
            }
            t[v2].mn += t[v].addv;
            t[v2].mx += t[v].addv;

            t[v].addv = 0;
        }
    }

    node comb(const node & a, const node & b) {
        node res;
        res.addv = 0;
        res.setv = NO;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        res.sz = a.sz + b.sz;
        return res;
    }

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize((n << 1) - 1, ZERO_NODE);
    }

    void build(vector<ll> & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vector<ll> & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = {0, NO, a[lx], a[lx], a[lx], 1};
            return;
        }
        else if(rx - lx != 1) {
            ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
            t[v] = comb(t[v1], t[v2]);
        }
    }

    void add(ll l, ll r, ll x, ll v, ll lx, ll rx) {
        if(l >= rx || r <= lx) return;
        if(l <= lx && r >= rx) {
        if(t[v].setv != NO) {
                t[v].setv += x;
                t[v].sum = t[v].setv * t[v].sz;
            } else {
                t[v].addv += x;
                t[v].sum += x * t[v].sz;
            }
            t[v].mn += x;
            t[v].mx += x;
            return;        
        }
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        add(l, r, x, v1, lx, m), add(l, r, x, v2, m, rx);
        t[v] = comb(t[v1], t[v2]);
    }

    void set(ll l, ll r, ll x, ll v, ll lx, ll rx) {
        if(l >= rx || r <= lx) return;
        if(l <= lx && r >= rx) {
            t[v].setv = x;
            t[v].mn = x;
            t[v].mx = x;
            t[v].sum = t[v].sz * x;
            t[v].addv = 0;
            return;
        }
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        set(l, r, x, v1, lx, m), set(l, r, x, v2, m, rx);
        t[v] = comb(t[v1], t[v2]);
    }

    void add(ll l, ll r, ll x) { add(l, r, x, 0, 0, n); }
    void set(ll l, ll r, ll x) { set(l, r, x, 0, 0, n); }
    ll get_sum(ll l, ll r) { return get(l, r, 0, 0, n).sum; }
    ll get_min(ll l, ll r) { return get(l, r, 0, 0, n).mn; }
    ll get_max(ll l, ll r) { return get(l, r, 0, 0, n).mx; }

    node get(ll l, ll r, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return {0, NO, 0, inf, -inf, 0};
        if(l <= lx && r >= rx) return t[v];
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        return comb(get(l, r, v1, lx, m), get(l, r, v2, m, rx));
    }
};

int main() {
    fastio;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll & c : a) cin >> c;
    SegTree t;
    // t.resize(n);
    t.build(a);
    // for(auto c : t.t) cout << c.n << ',' << c.add << ',' << c.sz << '|' << ' ';
    // cout << '\n';
    ll q;
    cin >> q;
    while(q--) {
        string type;
        cin >> type;
        if(type == "add") {
            ll l, r, val;
            cin >> l >> r >> val, l--;
            t.add(l, r, val);

            /*for(auto c : t.t) cout << c.n << ',' << c.add << ',' << c.sz << '|' << ' ';
            cout << '\n';*/
        }
        else if(type == "set") {
            ll l, r, val;
            cin >> l >> r >> val, l--;
            t.set(l, r, val);
        }
        else if(type == "sum") {
            ll l, r;
            cin >> l >> r, l--;
            cout << t.get_sum(l, r) << '\n';
        }
        else if(type == "min") {
            ll l, r;
            cin >> l >> r, l--;
            cout << t.get_min(l, r) << '\n';
        }
        else if(type == "max") {
            ll l, r;
            cin >> l >> r, l--;
            cout << t.get_max(l, r) << '\n';
        }
    }

    // for(ll c : t.t) cout << c << ' ';
}
