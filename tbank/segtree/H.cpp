#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

ll bsize = (1 << 7);

struct sqrt_decomp {
    ll n;
    vll a, block;

    void build(ll sz) {
        a.resize(sz, 0);
        block.resize((sz + bsize - 1) / bsize, 0);
    }

    void build(ll sz, vll & a) {
        this->a = a;
        block.resize((sz + bsize - 1) / bsize, 0);
        for(ll i = 0; i < sz; i++) block[i / bsize] += a[i];
    }

    void set(ll i) {
        block[i / bsize]++;
        a[i]++;
    }

    ll sum(ll l, ll r) {
        ll L = (l + bsize - 1) / bsize;
        ll R = r / bsize;
        ll ans = 0;
        if(L < R) {
            for(ll i = L; i < R; i++) ans += block[i];
            for(ll i = l; i < L * bsize; i++) ans += a[i];
            for(ll i = R * bsize; i <= r; i++) ans += a[i];
        }
        else {
            for(ll i = l; i <= r; i++) ans += a[i];
        }
        return ans;
    }
};

vector<ll> compress(vector<ll> a) {
    vector<ll> b = a;
    sort(all(b));
    unordered_map<ll, ll> m;
    for (ll x : b)
        if (!m.count(x))
            m[x] = m.size();
    for (ll &x : a)
        x = m[x];
    return a;
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    a = compress(a);
    vll pref(n), suf(n);
    sqrt_decomp cntPref, cntSuf;
    cntPref.build(n);
    for(ll i = 0; i < n; i++) {
        cntPref.set(a[i]);
        pref[i] = cntPref.sum(a[i] + 1, n - 1);
    }
    cntSuf.build(n);
    for(ll i = n - 1; i > -1; i--) {
        cntSuf.set(a[i]);
        suf[i] = cntSuf.sum(0, a[i] - 1);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) ans += pref[i] * suf[i];
    cout << ans << '\n';

}
