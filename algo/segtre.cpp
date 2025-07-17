#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct st {
    struct node {
        ll x, add, sz;
    };
    vector<node> tree;
    ll size;
    void pull(ll v) {
        push(v);
        push(v << 1), push((v << 1) | 1);
        tree[v].x = tree[v << 1].x + tree[(v << 1) | 1].x;
        tree[v].sz = tree[v << 1].sz + tree[(v << 1) | 1].sz;
    }
    void push(ll v) {
        if (v < size) {
            tree[v << 1].add += tree[v].add;
            tree[(v << 1) | 1].add += tree[v].add;
        }
        tree[v].x += tree[v].add * tree[v].sz;
        tree[v].add = 0;
    }

    void add(ll v, ll l, ll r,ll L, ll R, ll x) {
        if (tree[v].add != 0) push(v);
        if (r <= L || R <= l) return;
        if (L <= l && r <= R) {
            tree[v].add += x;
            push(v);
            return;
        }
        add(v << 1, l, (l + r) >> 1, L, R, x);
        add((v << 1) | 1, (l + r) >> 1, r, L, R, x);
        pull(v);
    }
    void add(ll l, ll r, ll x) {
        add(1, 0, size, l, r + 1, x);
    }
    ll get(ll v, ll l, ll r, ll L, ll R) {
        if (tree[v].add != 0) push(v);
        if (r <= L || R <= l) return 0;
        if (L <= l && r <= R) {
            return tree[v].x;
        }
        return get(v << 1, l, (l + r) >> 1, L, R) + get((v << 1) | 1, (l + r) >> 1, r, L, R);
    }
    ll get(ll l, ll r) {
        return get(1, 0, size, l, r + 1);
    }
    void build(vector<ll> & v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        tree.assign(size << 1, {0,0,0});
        for (ll i = 0; i < (ll) v.size(); i++) {
            tree[size + i].x = v[i];
            tree[size + i].sz = 1;
        }
        for (ll i = size - 1; i > 0; i--) pull(i);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    st s;
    vector<ll> v{3,4,6,7,8,1,0};
    ll n = v.size();
    s.build(v);
    mt19937 rnd(0);
    ll i = 0;
    while (1) {
        ll l = rnd() % n;
        ll r = l + rnd() % (n - l - 1);
        ll t = rnd()%2;
        if (t == 1) {
            ll x = rnd() % (ll)1e3;
            s.add(l,r,x);
            for (ll i =l; i <= r; i++)v[i]+=x;
            cout << l << " " << r << " " << x << endl;
        } else {
            ll x1 = s.get(l, r);
            ll x2 = 0;
            cout << l << " " << r <<  endl;
            for (ll i =l; i <= r; i++) x2 += v[i];
            if (x1 != x2) {
                cout << i << endl;
                cout << x1 << ' ' << x2 << endl;
                cout << l << ' ' << r << endl;
                break;
            }
        }

        i++;
    }
}
