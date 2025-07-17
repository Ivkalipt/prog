#include <iostream>
#include <vector>
 
#define fastio cin.tie(0) -> sync_with_stdio(0);
 
using namespace std;
using ll = long long;
using vll = vector<ll>;
 
struct SegTree {

    struct node {
        ll ind, len;
    };

    vll t;
    ll n;
    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize(2 * n - 1, 0);
        //build(a, 0, 0, n);
    }
 
    void build(vll &a) {
        resize(a.size());
        build(a, 0, 0, n);
    }
 
    void build(vll &a, ll v, ll lx, ll rx) {
        if(rx - lx == 1) {
            if(lx < a.size())
                t[v] = a[lx];
        }
        else {
            ll m = (rx + lx) / 2;
            build(a, 2 * v + 1, lx, m);
            build(a, 2 * v + 2, m, rx);
            t[v] = t[2 * v + 1] + t[2 * v + 2];
        }
    }
 
    void set(ll i, ll x, ll v, ll lx, ll rx) {
        if(rx - lx == 1) {
            t[v] = x;
            return;
        }
        ll m = (rx + lx) / 2;
        if(m > i) {
            set(i, x, 2 * v + 1, lx, m);
        }
        else {
            set(i, x, 2 * v + 2, m, rx);
        }
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
 
    void set(ll i, ll x) {
        set(i, x, 0, 0, n);
    }
 
    node get(ll l, ll r, ll cnt, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return {-2, 0};
        if(l <= lx && r >= rx && t[v] < cnt) return {-2, t[v]};
        if(rx - lx == 1) return {lx, 1};
        ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
        node vl = get(l, r, cnt, v1, lx, m);
        if(vl.ind != -2) return vl;
        node vr = get(l, r, cnt - vl.len, v2, m, rx);
        if(vr.ind != -2) return vr;
        return {-2, vl.len + vr.len};

    }

    node get(ll l, ll r, ll cnt) {
        return get(l, r, cnt, 0, 0, n);
    }
};
 
int main() {
    fastio;
    ll n, k;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c, c = (c ? 0 : 1);
    SegTree t;
    t.build(a);
    cin >> k;
    while(k--) {
        char type;
        cin >> type;
        if(type == 'u') {
            ll i, x;
            cin >> i >> x;
            t.set(i - 1, (x ? 0 : 1));
        }
        else {
            ll l, r, s;
            cin >> l >> r >> s;
            cout << t.get(l - 1, r, s).ind + 1 << '\n';
        }
    }
}
