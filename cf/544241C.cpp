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

ll c = (1 << 6);

struct sqrtDec {
    ll n;
    vll ad;
    vector<unordered_map<ll, ll>> block;

    void build(vll & a) {
        ll n = a.size();
        ll sz = (n + c - 1) / c;
        ad.resize(sz, 0);
        block.resize(sz);
        for(ll i = 0; i < n; i++)
            block[i / c][a[i]]++;
    }

    void add(ll l, ll r, ll x, vll & a) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        if(lx < rx) {
            for(ll i = lx; i < rx; i++)
                ad[i] += x;
            for(ll i = l; i < lx * c; i++) 
                block[i / c][a[i]]--, a[i] += x, block[i / c][a[i]]++;
            for(ll i = rx * c; i <= r; i++)
                block[i / c][a[i]]--, a[i] += x, block[i / c][a[i]]++;
        }
        else {
            for(ll i = l; i <= r; i++)
                block[i / c][a[i]]--, a[i] += x, block[i / c][a[i]]++;
        }
    }

    bool get(ll l, ll r, ll x, vll & a) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        if(lx < rx) {
            for(ll i = lx; i < rx; i++)
                if(block[i][x - ad[i]]) return true;
            for(ll i = l; i < lx * c; i++)
                if(a[i] + ad[i / c] == x) return true;
            for(ll i = rx * c; i <= r; i++)
                if(a[i] + ad[i / c] == x) return true;
        }
        else {
            for(ll i = l; i <= r; i++)
                if(a[i] + ad[i / c] == x) return true;
        }
        return false;
    }
};

int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    vll a(n);
    for(ll & c : a) cin >> c;
    sqrtDec t;
    t.build(a);
    while(m--) {
        char type;
        ll l, r, x;
        cin >> type >> l >> r >> x;
        l--, r--;
        if(type == '?') cout << (t.get(l, r, x, a) ? "YES" : "NO") << '\n';
        else t.add(l, r, x, a);
    }
}
