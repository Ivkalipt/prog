#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll inf = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ind = 1;
    ll cntd = 0;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(i * i == n) cntd++;
            else cntd += 2;
        }
    }
    if(k > cntd) cout << -1 << '\n', exit(0);
    // cout << cntd << ' ';
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(k == ind) cout << i << '\n', exit(0);
            if(k == cntd - ind + 1) cout << n / i << '\n', exit(0);
            ind++;
        }
    }

}
