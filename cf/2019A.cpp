#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 1;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, s1 = 0, s2 = 0, maxi1 = 0, maxi2 = 0;
        cin >> n;
        vll a(n);
        for(ll & c : a) cin >> c;
        for(ll i = 0; i < n; i++) {
            if(i & 1) {
                s2++;
                if(maxi2 < a[i]) maxi2 = a[i];
            }
            else {
                s1++;
                if(maxi1 < a[i]) maxi1 = a[i];
            }
        }
        cout << max(s1 + maxi1, s2 + maxi2) << '\n';
    }
}
