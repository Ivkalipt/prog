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

const ll c = (2 << 7);


struct root_decompose {
    ll n, sz;
    vll block;

    void build(vll & a) {
        n = a.size();
        sz = (n + c - 1) / c;
        block.resize(sz, -inf);
        for (ll i = 0; i < n; i++)
            block[i / c] = max(block[i / c], a[i]);
    }

    ll get(ll l, ll r, vll & a) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        ll ans = -inf;
        if (lx < rx) {
            for (ll i = lx; i < rx; i++)
                ans = max(ans, block[i]);
            for (ll i = l; i < lx * c; i++) 
                ans = max(ans, a[i]);
            for (ll i = rx * c; i <= r; i++)
                ans = max(ans, a[i]);
        } else {
            for (ll i = l; i <= r; i++)
                ans = max(ans, a[i]);
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
        ll l, r;
        cin >> l >> r;
        l--, r--;
        ll ans = t.get(l, r, a);
        cout << ans << '\n';
    }
}
