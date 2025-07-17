// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

pll isPrime(ll n) {
    ll s = 1, k = 1;
    for (ll i = 2; i <= n; i++) {
        if (n % i == 0) {
            s+=i;
            k++;
        }
    }
    return {k, s};
}

int main() {
    fastio;
    ll n;
    cin >> n;
    cout << isPrime(n).F << " " << isPrime(n).S;
    cout << "\n";
    return 0;
}