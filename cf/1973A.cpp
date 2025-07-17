#include <algorithm>
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

const ll inf = 1e9 + 7;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        vll a(3);
        cin >> a[0] >> a[1] >> a[2];
        if(a[0] + a[1] + a[2] & 1) {
            cout << -1 << '\n';
            continue;
        }
        a[2] -= a[0];
        ll ans = a[0];
        a[0] = 0;
        sort(all(a));
        ans += a[1];
        cout << ans << '\n';


    }
}
