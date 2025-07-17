#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;

const ll inf = 1e18;

struct SegTree {
    vector<ll> t;
    ll n;

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize((n << 1) - 1, -inf);
    }

    void build(vector<ll> & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vector<ll> & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = a[lx];
            return;
        }
        else if(rx - lx != 1) {
            ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
        }
    }

    void push(ll lx, ll rx, ll v) {
        if(t[v] == -inf || rx - lx == 1) return;
        ll v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        t[v1] = t[v], t[v2] = t[v], t[v] = -inf;
    }

    void set(ll l, ll r, ll x) {
        set(l, r, x, 0, 0, n);
    }

    void set(ll l, ll r, ll x, ll v, ll lx, ll rx) {
        push(lx, rx, v);
        if(r <= lx || l >= rx) return;
        if(l <= lx && r >= rx) {
            t[v] = x;
            return;
        }
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        set(l, r, x, v1, lx, m), set(l, r, x, v2, m, rx);
    }

    ll get(ll i) {
        return get(i, 0, 0, n);
    }

    ll get(ll i, ll v, ll lx, ll rx) {
        if(rx - lx == 1) return t[v];
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        if(m > i) return get(i, v1, lx, m);
        else return get(i, v2, m, rx);
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
    // for(ll c : t.t) cout << c << ' ';
    // cout << '\n';
    ll q;
    cin >> q;
    while(q--) {
        string type;
        cin >> type;
        if(type == "set") {
            ll l, r, val;
            cin >> l >> r >> val;
            l--;
            t.set(l, r, val);
        }
        else {
            ll x;
            cin >> x, x--;
            cout << t.get(x) << '\n';
        }
    }

    // for(ll c : t.t) cout << c << ' ';
}
