// #pragma GCC optimize ("O3, unroll-all-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

ll inf = 1e9 + 7;

ll pow10(ll n) {
    ll res = 1;
    while(n--) res *= 10;
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    k++;
    vll pows(n);
    ll ans = 0;
    for(ll & c : pows) cin >> c, c = pow10(c);
    for(ll i = 0; i < n; i++) {
        ll kk = k;
        if(i + 1 < n) kk = min(kk, pows[i + 1] / pows[i] - 1);
        ans += pows[i] * kk;
        k -= kk;
    }
    cout << ans << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
