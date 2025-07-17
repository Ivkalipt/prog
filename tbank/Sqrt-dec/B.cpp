#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

const ll c = (1 << 7);


struct root_decompose {
    ll n;
    vll block, ad;

    void build(vll & a) {
        n = a.size();
        ll sz = (n + c - 1) / c;
        block.resize(sz, 0);
        ad.resize(sz, 0);
        for (ll i = 0; i < n; i++)
            block[i / c] = max(block[i / c], a[i]);
    }

    void add(ll l, ll r, ll x, vll & a) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        if (lx < rx) {
            for (ll i = lx; i < rx; i++)
                ad[i] += x, block[i] += x;
            for (ll i = l; i < lx * c; i++)
                a[i] += x, block[i / c] = max(block[i / c], a[i] + ad[i / c]);
            for (ll i = rx * c; i <= r; i++)
                a[i] += x, block[i / c] = max(block[i / c], a[i] + ad[i / c]);
        } else {
            for (ll i = l; i <= r; i++)
                a[i] += x, block[i / c] = max(block[i / c], a[i] + ad[i / c]);
        }
    }

    ll maxis(ll l, ll r, vll & a) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        ll ans = 0;
            if (lx < rx) {
            for (ll i = lx; i < rx; i++)
                ans = max(ans, block[i]);
            for (ll i = l; i < lx * c; i++)
                ans = max(ans, a[i] + ad[i / c]);
            for (ll i = rx * c; i <= r; i++)
                ans = max(ans, a[i] + ad[i / c]);
        } else {
            for (ll i = l; i <= r; i++)
                ans = max(ans, a[i] + ad[i / c]);
        }
        return ans;
    }
};

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll & v : a) cin >> v;
    root_decompose t;
    t.build(a);
    ll k;
    cin >> k;
    while (k--) {
        char type;
        cin >> type;
        if (type == 'm') {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            cout << t.maxis(l, r, a) << ' ';
        }
        if (type == 'a') {
            ll l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            t.add(l, r, x, a);
        }
    }
}
