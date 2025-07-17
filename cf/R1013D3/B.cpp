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

void solve() {
    ll n, x;
    cin >> n >> x;
    vll a(n);
    for(ll & c : a) cin >> c;
    sort(rall(a));
    ll part = 0, cnt = 0;
    for(ll i = 0; i < n; i++) {
        part++;
        ll y = (x + a[i] - 1) / a[i];
        if(part * a[i] >= x) {
            cnt++, part = 0;
        }
    }
    cout << cnt << '\n';
    
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
