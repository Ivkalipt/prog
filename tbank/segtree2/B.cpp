#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;

const ll inf = 1e18;

struct SegTree {

    struct node {
        ll n, add, sz;
    };

    vector<node> t;
    ll n;

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize((n << 1) - 1, {0, 0, 0});
    }

    void build(vector<ll> & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vector<ll> & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = {a[lx], 0, 1};
            return;
        }
        else if(rx - lx != 1) {
            ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
            t[v] = {t[v1].n + t[v2].n, 0, t[v1].sz + t[v2].sz};
        }
    }

    void push(ll v) {
        if (t[v].add == 0) return;
        if (t[v].sz == 1) {
            t[v].n += t[v].add;
            t[v].add = 0;
            return;
        }
        t[2 * v + 1].add += t[v].add;
        t[2 * v + 2].add += t[v].add;
        t[v].n += t[v].add * t[v].sz;
        t[v].add = 0;
    }

    void add(ll l, ll r, ll x) {
        add(l, r, x, 0, 0, n);
    }

    void add(ll l, ll r, ll x, ll v, ll lx, ll rx) {
        push(v);
        if(r <= lx || l >= rx) return;
        if(l <= lx && r >= rx) {
            t[v].add += x;
            push(v);
            return;
        }
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        add(l, r, x, v1, lx, m), add(l, r, x, v2, m, rx);
        t[v].n = t[v1].n + t[v2].n;
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, n);
    }

    ll get(ll l, ll r, ll v, ll lx, ll rx) {
        push(v);
        if(r <= lx || l >= rx) return 0;
        if(l <= lx && r >= rx) return t[v].add * t[v].sz + t[v].n;
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        return get(l, r, v1, lx, m) + get(l, r, v2, m, rx);
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
        if(type == "add") {
            ll l, r, val;
            cin >> l >> r >> val, l--;
            t.add(l, r, val);

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
