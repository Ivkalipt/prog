#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;

const ll inf = 1e18;

int main() {
    ll a, b;
    cin >> a >> b;
    ld sq = sqrtl(a * a - 4 * b);
    ld x = (a + sq) / 2;
    ld y = (a - sq) / 2;
    cout << y << ' ' << x << '\n';
}
