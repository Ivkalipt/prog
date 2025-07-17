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

const ll inf = 1e18;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    vll pm(n), ss(n + 1);
    pm[0] = a[0];
    ss[n - 1] = a[n - 1];
    for(ll i = 1; i < n; i++) {
        pm[i] = max(a[i], pm[i - 1]);
    }
    for(ll i = n - 2; i > -1; i--) {
        ss[i] = ss[i + 1] + a[i];
    }
    vll ans;
    for(ll i = 0; i < n; i++) {
        ans.push_back(pm[i] + ss[i + 1]);
    }
    reverse(all(ans));
    for(ll c : ans) cout << c << ' ';
    cout << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
