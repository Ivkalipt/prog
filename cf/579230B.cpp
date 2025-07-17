#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

struct Node {
    ll index, maxVal;
};


struct Seg_tree {
    
    vector<Node> t;
    ll n;

    void resize(ll sz) {
        n = 1;
        while(n < sz) n <<= 1;
        t.resize(2 * n - 1, {-1, -inf});
    }

    void build(vll & a) {
        resize(a.size());
        build(a, 0, 0, n);
    }

    void build(vll & a, ll v, ll lx, ll rx) {
        if(rx - lx == 1 && lx < a.size())
            t[v] = {lx, a[lx]};
        else if(rx - lx != 1) {
            ll m = (rx + lx) / 2, v1 = 2 * v + 1, v2 = 2 * v + 2;
            build(a, v1, lx, m);
            build(a, v2, m, rx);
            if(t[v1].maxVal > t[v2].maxVal) t[v] = t[v1];
            else t[v] = t[v2];
        }
    }

    /*void set(ll i, ll x) {
        set(i, x, 0, 0, n);
    }

    void set(ll i, ll x, ll v, ll lx, ll rx) {
        if(rx - lx == -1) {
            t[v] = {i, x};
            return;
        }
        ll m = (lx + rx) / 2, v1 = 2 * v + 1, v2 = 2 * v + 2;
        if(m > i) set(i, x, v1, lx, m);
        else set(i, x, v2, m, rx);
        if(t[v1].maxVal > t[v2].maxVal) t[v] = t[v1];
        else t[v] = t[v2];
    }*/

    Node maxis(ll l, ll r) {
        return maxis(l, r, 0, 0, n);
    }

    Node maxis(ll l, ll r, ll v, ll lx, ll rx) {
        if(r <= lx || l >= rx) {
            return {-1, -inf};
        }
        if(lx >= l && rx <= r) {
            return t[v];
        }
        ll m = (lx + rx) / 2, v1 = 2 * v + 1, v2 = 2 * v + 2;
        Node a = maxis(l, r, v1, lx, m), b = maxis(l, r, v2, m, rx);
        return (a.maxVal > b.maxVal ? a : b);
    }
};

int main() {
    fastio;
    ll n, m;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    Seg_tree t;
    t.build(a);
    cin >> m;
    while(m--) {
        ll t1, t2;
        cin >> t1 >> t2;
        Node maxi = t.maxis(t1 - 1, t2);
        cout << maxi.maxVal << ' ' << maxi.index + 1 << '\n';
    }
}
