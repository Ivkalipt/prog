#include <algorithm>
#pragma GCC optimize ("O3,unroll-loops")
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

const ll c = (2 << 8);


struct root_decompose {
    ll n;
    vector<pll> block;
    
    void build(vll & a) {
        n = a.size();
block.resize((n + c - 1) / c+10, {-inf, -1});
        for(ll i = 0; i < n; i++)
            if(a[i] > block[i / c].F) 
                block[i / c] = {a[i], i};
    }

    pll get(ll l, ll r, vll & a) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        pll ans = {-inf, -1};
        if(lx < rx) {
            for(ll i = lx; i < rx; i++)
                if(block[i].F > ans.F) 
                    ans = block[i];
            for(ll i = l; i < lx * c; i++)
                if(a[i] > ans.F) 
                    ans = {a[i], i};
            for(ll i = rx * c + 1; i <= r; i++)
                if(a[i] > ans.F) 
                    ans = {a[i], i};
        }
        else
            for(ll i = l; i <= r; i++)
                if(a[i] > ans.F) {
                    ans = {a[i], i};
                }
        return ans;
    }
};

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & v : a) cin >> v;
    root_decompose t;
    t.build(a);
    ll k;
    cin >> k;
    while(k--) {
        ll l, r;
        cin >> l >> r;
        l--, r--;
        pll ans = t.get(l, r, a);
        cout << ans.F << ' ' << ans.S + 1 << '\n';
    }
}
