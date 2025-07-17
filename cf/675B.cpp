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
    ll n, a, b, c, d, cnt = 0;
    cin >> n >> a >> b >> c >> d;
    for(ll x1 = 1; x1 <= n; x1++) {
        ll x2 = b + x1 - c;
        ll x4 = a + x1 - d;
        ll x5 = b + x4 - c;
        if(1 <= x2 && x2 <= n && 1 <= x4 && x4 <= n && 1 <= x5 && x5 <= n) {
            cnt++;
        }
    }
    cout << cnt * n << '\n';
}
