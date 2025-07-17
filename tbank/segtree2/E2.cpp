#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;

const ll inf = 1e18;

struct SegTree {

    struct node {
        ll a, d, add, sum, sz;
    };

    vector<node> t;
    ll n;

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize((n << 1) - 1, {0, 0, 0, 0, 1});
    }

    void build(ll sz) {
        resize(sz);
        build(0, 0, n);
    }

    void build(ll v, ll lx, ll rx) {
        if(rx - lx == 1) {
            t[v].sz = 1;
        }
        else if(rx - lx != 1) {
            ll m = (rx + lx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
            build(v1, lx, m);
            build(v2, m, rx);
            t[v].sz = t[v1].sz + t[v2].sz;
        }
    }

    void push(ll lx, ll rx, ll v) {
        ll v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        if(t[v].add != 0) {
            t[v1].add += t[v].add;
            t[v1].sum += t[v].add * t[v1].sz;

            t[v2].add += t[v].add;
            t[v2].sum += t[v].add * t[v2].sz;
            
            t[v].add = 0;
        }
        if(t[v].a != 0 || t[v].d != 0) {
            ll a = t[v].a, d = t[v].d, ar = a + d * t[v1].sz;

            t[v1].a += a;
            t[v1].d += d;
            t[v1].sum += a * t[v1].sz + d * (t[v1].sz - 1) * t[v1].sz / 2;

            t[v2].a += ar;
            t[v2].d += d;
            t[v2].sum += ar * t[v2].sz + d * (t[v2].sz - 1) * t[v2].sz / 2;
            
            t[v].a = 0;
            t[v].d = 0;
        }
    }

    void addx(ll l, ll r, ll x) {
        addx(l, r, x, 0, 0, n);
    }

    void addx(ll l, ll r, ll x, ll v, ll lx, ll rx) {
        if(r <= lx || l >= rx) return;
        if(l <= lx && r >= rx) {
            t[v].add += x;
            t[v].sum += x * t[v].sz;
            return;
        }
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        addx(l, r, x, v1, lx, m), addx(l, r, x, v2, m, rx);
        t[v].sum = t[v1].sum + t[v2].sum;
    }

    void addp(ll l, ll r, ll a, ll d) {
        addp(l, r, a, d, 0, 0, n);
    }

    void addp(ll l, ll r, ll a, ll d, ll v, ll lx, ll rx) {
        if(r <= lx || l >= rx) return;
        if(l <= lx && r >= rx) {
            t[v].a += a + (lx - l) * d;
            t[v].d += d;
            t[v].sum += (a + (lx - l) * d) * t[v].sz + (t[v].sz - 1) * d * t[v].sz / 2;
            // cout << lx - l << ' ' << t[v].sz << '\n';
            return;
        }
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        addp(l, r, a, d, v1, lx, m), addp(l, r, a, d, v2, m, rx);
        t[v].sum = t[v1].sum + t[v2].sum;
    }

    ll get(ll l, ll r) {
        return get(l, r, 0, 0, n);
    }

    ll get(ll l, ll r, ll v, ll lx, ll rx) {
        if(r <= lx || l >= rx) return 0;
        if(l <= lx && r >= rx) return t[v].sum;
        push(lx, rx, v);
        ll m = (lx + rx) >> 1, v1 = (v << 1) + 1, v2 = (v << 1) + 2;
        return get(l, r, v1, lx, m) + get(l, r, v2, m, rx);
    } 
};

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    SegTree t;
    t.build(n);
    while (m--) {
        char type;
        cin >> type;
        if (type == '?') {
            ll l, r;
            cin >> l >> r, l--;
            cout << t.get(l, r) << '\n';
        } else if (type == 'R') {
            ll i, q;
            cin >> i >> q, i--;
            if(i - q + 1 >= 0)
                t.addp(i - q + 1, i + 1, 1, 1);
            else
                t.addp(0, i + 1, q - i, 1);
            // cout << q - i << ' ';
            // cout << t.get(0, 1) << ' ' << t.get(1, 2) << ' ' << t.get(2, 3) << ' ' << t.get(3, 4) << '\n';
            t.addp(i + 1, min(n, i + q), q - 1, -1);
        } else {
            ll l, r, x;
            cin >> l >> r >> x, l--;
            t.addx(l, r, -x);
        }
    }
}

/*int main() {
    SegTree t;
    t.build(5);
    cout << t.get(0, 1) << ' ' << t.get(1, 2) << ' ' << t.get(2, 3) << ' ' << t.get(3, 4) << '\n';
    t.addp(0, 3, 2, 1);

    cout << t.get(0, 1) << ' ' << t.get(1, 2) << ' ' << t.get(2, 3) << ' ' << t.get(3, 4) << '\n';
}*/
