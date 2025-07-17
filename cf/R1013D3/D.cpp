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

ll count(ll n, ll m, ll w) {
    ll ans = (m / (w + 1)) * w + m - (m / (w + 1)) * (w + 1);
    return ans * n;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 0, r = m;
    while(r - l > 1) {
        ll mid = (l + r) >> 1;
        if(count(n, m, mid) >= k) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
