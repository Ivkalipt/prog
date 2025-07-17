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

struct Node {
    ll seg, pref, suf, sum;
};

struct Seg_tree {

    vector<Node> t;
    ll n;

    Node comb(Node a, Node b) {
        return {
            max({a.seg, b.seg, a.suf + b.pref}),
            max({a.pref, a.sum + b.pref}),
            max({b.suf, a.suf + b.sum}),
            a.sum + b.sum
        };
    }

    Node one(ll x) {
        return {
            max(x, 0LL), max(x, 0LL), max(x, 0LL), x
        };
    }

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.assign(2 * n - 1, {0, 0, 0, 0});
    }

    void build(vll & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vll & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1) {
            if(lx < a.size())
                t[v] = one(a[lx]);
        }
        else {
            ll m = (lx + rx) / 2, v1 = 2 * v + 1, v2 = 2 * v + 2;
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
        ll m = (lx + rx) / 2, v1 = 2 * v + 1, v2 = 2 * v + 2;
        if(m > i) set(i, x, v1, lx, m);
        else set(i, x, v2, m, rx);
        t[v] = comb(t[v1], t[v2]);
    }

    /*Node calc(ll l, ll r) {
        return calc(l, r, 0, 0, n);
    }

    Node calc(ll l, ll r, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return {0, 0, 0, 0};
        if(l <= lx && r >= rx) return t[v];
        ll m = (lx + rx) / 2, v1 = 2 * v + 1, v2 = 2 * v + 2;
        return comb(calc(l, r, v1, lx, m), calc(l, r, v2, m, rx));
    }*/
};

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for(ll & c : a) cin >> c;
    Seg_tree t;
    t.build(a);
    cout << t.t[0].seg << '\n';
    while(m--) {
        ll i, v;
        cin >> i >> v;
        t.set(i, v);
        cout << t.t[0].seg << '\n';
    }
}
