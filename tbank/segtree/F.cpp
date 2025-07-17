#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

ll bsize = (1 << 7);

struct sqrtDec {
    ll n;
    vll a, block;

    void build(ll sz, vll & a) {
        this->a = a;
        block.resize((sz + bsize - 1) / bsize, 0);
        for(ll i = 0; i < sz; i++)
            block[i / bsize] += a[i];
    }

    void set(ll i, ll x) {
        block[i / bsize] -= a[i];
        a[i] = x;
        block[i / bsize] += a[i];
    }

    ll get(ll l, ll r, ll cnt) {
        ll lx = (l + bsize - 1) / bsize;
        ll rx = r / bsize;
        ll ind = 0;
        if(lx < rx) {
            for(ll i = l; i < lx * bsize; i++) {
                cnt -= a[i];
                ind++;
                cout << ind << '!' << cnt << '\n';
                if(cnt == 0) return ind;
            }
            for(ll i = lx; i < rx; i++) {
                if(block[i] < cnt) {
                    cnt -= block[i], ind += bsize;
                    cout << ind << ' ' << cnt << '\n';
                }
                else {
                    for(ll j = i * bsize; j <= (i + 1) * bsize - 1; j++) {
                        cnt -= a[j]; 
                        ind++;
                        cout << ind << '?' << cnt << ' ' << i << ' ' << j << '\n';
                        if(cnt == 0) return ind;

                    }
                }
            }
            for(ll i = rx * bsize; i <= r; i++) {
                cnt -= a[i];
                ind++;
                cout << ind << '.' << cnt << '\n';
                if(cnt == 0) return ind;
            }
        }
        else {
            for(ll i = l; i <= r; i++) {
                cnt -= a[i];
                ind++;
                if(cnt == 0) return ind;
            }
        }
        return -1;
    }    
};

int main() {
    fastio;
    ll n, k;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c, c = (c ? 0 : 1);
    sqrtDec t;
    t.build(n, a);
    cin >> k;
    while(k--) {
        char type;
        cin >> type;
        if(type == 'u') {
            ll i, x;
            cin >> i >> x;
            t.set(i - 1, (x ? 0 : 1));
        }
        else {
            ll l, r, s;
            cin >> l >> r >> s;
            cout << t.get(l - 1, r - 1, s) + l - 1 << '\n';
        }
    }
}
