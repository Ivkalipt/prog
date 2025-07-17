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

ll mod = 1e9 + 7;

ll powByMod(ll a, ll n) {
    if(n == 0) return 1;
    if (n % 2 == 0) return powByMod((a * a) % mod, n / 2);
    return (a * powByMod(a, n - 1)) % mod;
}

ll rev(ll a) {
    return powByMod(a, mod - 2);
}

ll C(ll n, ll k, vll & fct) {
    return ((fct[n] * rev(fct[k])) % mod * rev(fct[n - k])) % mod;
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    ll m = n / 2;
    ll s = 0, f = 0;
    vll fct(1000001, 1);
    for(ll i = 1; i <= 1e6; i++) {
        fct[i] = (fct[i - 1] * i) % mod;
    }
    /*for(ll i = 0; i < m; i++) {
        s += ((C(m - 1, i, fct) % mod) * (a[2 * i] % mod)) % mod;
        f += ((C(m - 1, i, fct) % mod) * (a[2 * i + 1] % mod)) % mod;
    }*/
    for(ll k = 0; k < m; k++){
        ll c = C(m - 1, k, fct); 
        s = (s + c * a[2 * k]) % mod;
        f = (f + c * a[2 * k + 1]) % mod;
    }
    cout << s << ' ' << f << '\n';
}
