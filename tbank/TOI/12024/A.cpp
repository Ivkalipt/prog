#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

int main() {
    ll n;
    cin >> n;
    ll k = 0;
    vpll a(n);
    for(pll & c : a) cin >> c.F >> c.S;
    sort(all(a), [](pll x, pll y) {
            return min(x.F, x.S) < min(y.F, y.S);
            });
    for(ll i = 0; i < n; i++) {
        if(a[i].F >= 2 * (k + 1) - 1 && a[i].S >= 2 * (k + 1) - 1) k++; 
    }
    cout << k << '\n';
}
