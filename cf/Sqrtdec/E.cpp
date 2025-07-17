#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second

ll c = (1 << 7);

struct sqrtDec {
    ll n;
    vll block;

    void build(vll & a) {
        ll n = a.size();
        ll sz = (n + c - 1) / c;
        block.resize(sz, 0);
        /*for(ll i = 0; i < n; i++)
            block[i / c] += a[i];*/
    }

    void set(ll ind, ll x, vll & a) {
        ll d = ind / c;
        block[d] -= a[ind]; 
        a[ind] = x;
        block[d] += a[ind];
        /*for(ll c : block) cout << c << ' ';
        cout << '\n';*/
    }

    ll get(ll l, ll r, vll & a) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        ll ans = 0;
        if(lx < rx) {
            for(ll i = lx; i < rx; i++)
                ans += block[i];
            // cout << ans << '\n';
            for(ll i = l; i < lx * c; i++)
                ans += a[i];
            // cout << ans << '\n';
            for(ll i = rx * c; i <= r; i++)
                ans += a[i];
            // cout << ans << '\n';
        }
        else {
            for(ll i = l; i <= r; i++)
                ans += a[i];
        }
        return ans;
    }
};

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vll a(n, 0);
    sqrtDec t;
    t.build(a);
    while(m--) {
        char type;
        cin >> type;
        if(type == 'A') {
            ll i, x;
            cin >> i >> x;
            t.set(i - 1, x, a);
        }
        else {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            cout << t.get(l, r, a) << '\n';
        }
    }
}
