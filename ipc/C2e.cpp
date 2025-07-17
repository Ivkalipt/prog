#pragma GCC optimize ("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;



int main() {
    fastio;
    ll m, n;
    bool flag = 0;
    cin >> m >> n;
    vll primes(n+1);
    for (int i = 0; i < n + 1; i++) primes[i] = i;
    for(ll i = 2; i <= n; i++) {
        if(!primes[i]) continue;
        for(ll j = i*i; j <= n; j+= i) primes[j] = 0;

    }
    for(auto c:primes) {
        if(c && c >= m && c != 1) {
            cout << c << "\n";
            flag = 1;
        }
    }
    if(!flag) {
        cout << "Absent";
    }
    return 0;
}

