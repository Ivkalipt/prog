// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

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
    ll m, n, v, h, A = 0, B = 0, C;
    cin >> m >> n >> v >> h;
    vll x(v + 2, 0), y(h + 2, 0);
    for(ll i = 1; i <= v; i++) cin >> x[i];
    for(ll i = 1; i <= h; i++) cin >> y[i];
    C = (m * n) - (m - v) * (n - h);
    x[v + 1] = m; y[h + 1] = n;
    for(ll i = 1; i <= v + 1; i++) {
        for(ll j = 1; j <= h + 1; j++) {
            ll a = max(x[i] - x[i - 1], x[i] - x[i - 1]) - 1;
            ll b = min(y[j] - y[j - 1], y[j] - y[j - 1]) - 1;
            if((i == 0 || i == v + 1) && !(j == 0 || j == h + 1)) {
                if(a - 1 < 0 || b - 2 < 0) continue;
                B += (a - 1) * (b - 2);
            }
            else if((j == 0 || j == h + 1) && !(i == 0 || i == v + 1)) {
                if(a - 2 < 0 || b - 1 < 0) continue;
                B += (a - 2) * (b - 1);
            }
            else if((j == 0 || j == h + 1) && (i == 0 || i == v + 1)) {
                if(a - 1 < 0 || b - 1 < 0) continue;
                B += (a - 1) * (b - 1);
            }
            else {
                if(a - 2 < 0 || b - 2 < 0) continue;
                B += (a - 2) * (b - 2);
            }
        }
    }
    A = m * n - B - C;
    cout << A << ' ' << B << ' ' << C << '\n';
}
