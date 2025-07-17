// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll unsigned long long
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
    ll n, m, sum;
    cin >> n >> m;
    sum = (1ll << (n * m - 1));
    for(ll i = 2; i <= n; i++) {
        for(ll j = 2; j <= m; j++) {
            sum += (1ll << ((n - 1) * (m - 1) + n - i + m - j));
        }
    }
    cout << ' ' << sum << '\n';
}


