// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#pragma GCC optimize ("Ofast")

#include <iostream>
#include <cmath>
// #include <vector>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

ll sqrt_up(ll x) {
    return (ll)ceil(sqrt(x));
}

ll sqrt_down(ll x) {
    return (ll)floor(sqrt(x));
}

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0;
    for(ll y = 1; y <= 1e6; y++) {
        ll y3 = y * y * y;
        if(y3 >= a && y3 <= b) {
            ll r = min(y3 + k, b);
            ll l = max(y3 - k, a);
            ans += sqrt_down(r) - sqrt_up(l) + 1;
        }
    }
    cout << ans << '\n';
}
