// #pragma GCC optimize ("O3, unroll-all-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

bool is_prime(ll x) {
    if(x == 1) return false;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

void solve() {
    ll x, k;
    cin >> x >> k;
    if((is_prime(x) && k == 1) || (k == 2 && x == 1)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
