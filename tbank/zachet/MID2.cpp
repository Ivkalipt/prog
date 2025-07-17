#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define ld long double
#define vpll vector<pll>
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
    vll a(n);
    for(ll & c : a) cin >> c;
    if(n == 1) cout << 0 << '\n', exit(0);
    sort(all(a));
    ll s = a[0] * (n - 1) + a[1] * (n - 1);
    for(ll i = 2; i < n; i++) {
        s += a[i] * (n - i);
    }
    cout << s << '\n';
}
