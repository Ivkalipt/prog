#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second

ll inf = 1e16;

ll isGood(ll n) {
    ll a = 1;
    ll cnt = 0;
    while(a <= n) {
        ll b = a;
        for(ll i = 0; i < log2(a) + 1; i++) {
            if(b > n) break;
            cnt++;
            b |= b >> 1; 
        }
        a <<= 1;
    }
    if(a > n) a >>= 1;
    return cnt;
}

int main() {
    ll n;
    cin >> n;
    cout << isGood(n) << '\n';
}
