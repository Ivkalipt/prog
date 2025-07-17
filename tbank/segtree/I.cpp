#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e18;

struct segTree {
    ll n;
    struct node {
        ll mx, mn;
    };
    vector<node> t;

    node cmp(node a, node b) {
        return {max(a.mx, b.mx), min(a.mn, b.mn)};
    }

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize(2 * n - 1, {-inf, inf});
    }

    void build(vll & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vll & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size()) {
            t[v] = {a[lx], a[lx]};
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
            t[v].mx += x, t[v].mn += x;
            return;
        }
        ll m = (lx + rx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
        if(i < m) set(i, x, v1, lx, m);
        else set(i, x, v2, m, rx);
        t[v] = cmp(t[v1], t[v2]);
    }

    node get(ll l, ll r) {
        return get(l, r, 0, 0, n);
    }

    node get(ll l, ll r, ll v, ll lx, ll rx) {
        if(r <= lx || l >= rx) return {-inf, inf};
        if(l <= lx && rx <= r) return t[v];
        ll m = (lx + rx) >> 1, v1 = 2 * v + 1, v2 = 2 * v + 2;
        return cmp(get(l, r, v1, lx, m), get(l, r, v2, m, rx));
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vll a(n + 1), b(n);
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++)
        b[i] = a[i + 1] - a[i]; 
    // for(ll c : b) cout << c << ' ';
    segTree t;
    t.build(b);
    while(m--) {
        int ty;
        cin >> ty;
        if(ty == 1) {
            ll l, r;
            cin >> l >> r;
            if(l < r) {
                segTree::node f = t.get(l, r);
                if(f.mx <= 1) cout << "Yes\n";
                else cout << "No\n";
            }
            else {
                segTree::node f = t.get(r, l);
                if(f.mn >= -1) cout << "Yes\n";
                else cout << "No\n";
            }
        }
        else {
            ll l, r, d;
            cin >> l >> r >> d;
            l--;
            t.set(l, d), t.set(r, -d);
        }
    }
}
