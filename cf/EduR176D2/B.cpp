#include <algorithm>
#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")
 
#include <bits/stdc++.h>
 
#define fastio cin.tie(0)->sync_with_stdio(0);
 
using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;
 
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
const ll inf = 1e18;
 
void solve() {
    ll n, k, s = 0;
    cin >> n >> k;

    vll a(n);
    for(ll & c : a) cin >> c;
    if(k == 1) {
        ll mx = *max_element(all(a));
        if(a[0] == mx) cout << 
    }
    sort(rall(a));
    for(ll i = 0; i <= k; i++) {
        s += a[i];
    }
    cout << s << '\n';
}
 
int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
