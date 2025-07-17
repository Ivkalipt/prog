#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;

ll inf = 1e16;

struct SegTree {
    struct node {
        ll val, mn;
    };

    vector<node> t;
    ll n;

    const ll NO = inf;

    node comb(node x, node y) {
        return {0, min(x.mn, y.mn)};
    }

    void push(ll lx, ll rx, ll v) {
        if(rx - lx == 1) {
            t[v].mn = t[v].val;
            t[v].val = NO;
            return;
        }
        if(t[v].val != NO) {
            ll v1 = (v << 1) + 1, v2 = (v << 1) + 2;
            t[v1].val = t[v].val;
            t[v2].val = t[v].val;
            t[v1].mn = t[v].val;
            t[v2].mn = t[v].val;
            t[v].val = NO;
        }
    }

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize((n << 1) - 1, {NO, inf});
    }

    void build(vector<ll> & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vector<ll> & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = {NO, a[lx]};
            return;
        }
        else if(rx - lx != 1) {
            ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
            t[v].mn = min(t[v1].mn, t[v2].mn);
        }
    }

    void set(ll l, ll r, ll x) {
        set(l, r, x, 0, 0, n);
    }

    void set(ll l, ll r, ll x, ll v, ll lx, ll rx) {
        if(l >= rx || r <= lx) return;
        if(l <= lx && r >= rx) {
            t[v].val = x;
            t[v].mn = x;
            return;
        }
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        set(l, r, x, v1, lx, m), set(l, r, x, v2, m, rx);
        t[v].mn = min(t[v1].mn, t[v2].mn);
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, n);
    }

    ll get(ll l, ll r, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return inf;
        if(l <= lx && r >= rx) return t[v].mn;
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        return min(get(l, r, v1, lx, m), get(l, r, v2, m, rx));
    }
};

int main() {
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
        if(type == "set") {
            ll l, r, val;
            cin >> l >> r >> val, l--;
            t.set(l, r, val);

            /*for(auto c : t.t) cout << c.n << ',' << c.add << ',' << c.sz << '|' << ' ';
            cout << '\n';*/
        }
        else {
            ll l, r;
            cin >> l >> r, l--;
            cout << t.get(l, r) << '\n';
        }
    }

    // for(ll c : t.t) cout << c << ' ';
}
