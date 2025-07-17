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

ll inf = 1e16;

int main() {
    ll n;
    cin >> n;
    map<ll, ll> a;
    for(ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        ll cnt = 1;
        while(k % 2 == 0) k /= 2, cnt *= 2;
        a[k] += cnt;
    }
    for(pll c : a) {
        if(c.S > 1) a[c.F * 2] += c.S / 2;
    }
    ll ans = -inf;
    for(pll c : a) {
        if(c.F > ans) ans = c.F;
    }
    cout << ans << '\n';
}
