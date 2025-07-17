// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;


int cntd(ll n) {
    if(n == 1) return 1;
    ll cnt = 2;
    ll i = 2;
    while (i * i < n) {
        if (n % i == 0) {
            cnt += 2;
        }
        i += 1;
    }
    if (i * i == n) {
        cnt += 1;
    }
    return cnt;
}


int main() {
    fastio;
    ll n;
    cin >> n;
    cout << cntd(n);
    cout << "\n";
    return 0;
}