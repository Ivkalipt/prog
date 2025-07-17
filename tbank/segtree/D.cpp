#include <iostream>
#include <vector>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
const ll inf = 1e9 + 1;

struct SegTree {
    struct node {
        ll mx, cnt;
    };

    vector<node> t;
    ll n;
    constexpr static node ZERO = {0, -1};
    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize(2 * n - 1, ZERO);
    }

    void build(vll & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    node one(ll x) {
        return {x, 1};
    }

    node cmp(node a, node b) {
        if(a.mx > b.mx) return a;
        if(a.mx < b.mx) return b;
        return {a.mx, b.cnt + a.cnt};
    }

    void build(vll & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = one(a[lx]);
        }
        else if(rx - lx != 1) {
            ll m = (lx + rx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
            t[v] = cmp(t[v1], t[v2]);
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
        ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
        if(m > i) set(i, x, v1, lx, m);
        else set(i, x, v2, m, rx);
        t[v] = cmp(t[v1], t[v2]);
    }

    node get(ll l, ll r) {
        return get(l, r, 0, 0, n);
    }

    node get(ll l, ll r, ll v, ll lx, ll rx) {
        if(lx >= r || rx <= l) return ZERO;
        if(l <= lx && r >= rx) return t[v];
        ll m = (rx + lx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
        return cmp(get(l, r, v1, lx, m), get(l, r, v2, m, rx));
    }
};

int main() {
    fastio;
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    SegTree t;
    t.build(a);
    ll k;
    cin >> k;
    while(k--) {
        char type;
        cin >> type;
        if(type == 'A') {
            ll i, x;
            cin >> i >> x;
            i--;
            t.set(i, x);
        }
        else {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << t.get(l, r).cnt << ' ';
        }
    }
}
