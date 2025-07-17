// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#include <iomanip>
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

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

int main() {
    ll n; 
    ld s = 1;
    cin >> n;
    for(ll i = 1; i <= n; i++) {
          if(i & 1) {
              s *= (i + 1.0) / i;
              //cout << (i + 1.0) / i << ' ';
          }
          else {
              s *= i / (i + 1.0);
              //cout << i / (i + 1.0) << ' ';
          }
    }
    cout << setprecision(10) << fixed << s << '\n';
}
