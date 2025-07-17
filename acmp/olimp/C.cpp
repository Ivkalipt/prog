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
    ll a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    if(c <= b) {
        cout << c - e - a + d - 1 << ' ';
    }
    else {
        cout << (c - e - a) + (b - c + d) << ' ';
    }

    if(d == e) {
        cout << - a + b << '\n';
    }
    else {
        cout << - a + b - 1 << '\n';
     }

}
