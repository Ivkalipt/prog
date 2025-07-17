// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#pragma GCC optimize ("Ofast")

#include <iostream>
#include <cmath>

#define ll long long
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

int main() {
    ll n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    ll l = 0;
    ll r = min(w, h) + 1;
    while(r - l > 1) {
        ll m = (l + r) / 2;
        if((w / (a + 2 * m)) * (h / (b + 2 * m)) < n && (h / (a + 2 * m)) * (w / (b + 2 * m)) < n) {
            r = m;
        }
        else {
            l = m;
        }
        // cout << l << ' ' << r << '\n';
    }

    cout << l << '\n';
}
