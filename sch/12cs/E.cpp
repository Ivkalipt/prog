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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

ll c = (1 << 7);

struct sqrtDec {
    ll n;
    vll a, block;
    string ans;

    void build(ll sz) {
        n = sz;
        a.resize(sz, 'A' - 1);
        block.resize((sz + c - 1) / c, 'A' - 1);
    }

    void set(ll l, ll r, char x) {
        ll lx = (l + c - 1) / c;
        ll rx = r / c;
        if(lx < rx) {
            for(ll i = lx; i < rx; i++)
                block[i] = x - 'A' + 1;
            for(ll i = l; i < lx * c; i++)
                a[i] = x - 'A' + 1 - block[i / c];
            for(ll i = rx * c; i <= r; i++)
                a[i] = x - 'A' + 1 - block[i / c];
        }
        else
            for(ll i = l; i <= r; i++)
                a[i] = x;
    }

    string get() {
        ans = "";
        for(ll i = 0; i < n; i++) {
            ans += a[i];
            cout << a[i] << ' ';
        }
        cout << '\n';
        for(ll v : a) cout << v << ' ';
        cout << '\n';
        for(ll v : block) cout << v << ' ';
        return ans;
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    sqrtDec t;
    t.build(n);
    while(q--) {
        char x;
        ll i, j;
        t.set(i - 1, j - 1, x);
    }
    cout << t.get() << '\n';
}
