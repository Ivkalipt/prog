#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

ll G(vll & a, vll & b, ll k, ll n) {
    for(ll i = 0; i < a.size(); i++) {
        if(a[i] * n > b[i]) k -= (a[i] * n - b[i]);
    }
    return k;
}

int main() {
    ll n, k;
    cin >> n >> k;
    vll a(n), b(n);
    for(ll & c : a) cin >> c;
    for(ll & c : b) cin >> c;
    ll l = -1, r = 1e9 + 1;
    while(r - l > 1) {
        ll mid = (r + l) / 2;
        if(G(a, b, k, mid) < 0) r = mid;
        else l = mid;
        // cout << l << ' ' << r << '\n';
    }
    cout << l;
}
