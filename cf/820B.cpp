#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;

ll inf = 1e16;

int main() {
    ld n, a;
    cin >> n >> a;
    ld d = 360 / (2 * n);
    ld ds = 0;
    ld ans = inf;
    ll three = 0;
    for(ll i = 3; i <= n; i++) {
        ds += d;
        if(ans > abs(ds - a)) {
            ans = abs(ds - a);
            three = i;
        }

    }
    cout << "2 1 " << three << '\n';

}
