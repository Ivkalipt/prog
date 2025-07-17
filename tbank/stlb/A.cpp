#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vpll a(n);
    for(pll & c : a) cin >> c.F >> c.S;
    sort(all(a));
    ll fin = 0, s = 0;
    for(ll i = 0; i < n; i++) {
        fin += a[i].F;
        s += a[i].S - fin;
    }
    cout << s << '\n';
    
}
