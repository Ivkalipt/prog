#include <cmath>
#include <iomanip>
#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;

const ll inf = 1e18;
const ld PI = 3.1415926535;

/*ll integro(ld a, ld b, ld eps, ld n, ld d, ld c) {
    ld Integral = eps * (f(a, d, c) + f(b, d, c)) / 2;
    for(ll i = 1; i < n; i++)
	    Integral += eps * f(a + eps * i, d, c);
    return Integral;
}*/

ld f(ld h, ld r, ld l) {
    ld H = h - r;
    return (H * sqrtl(r * r - H * H) + r * r * asinl(H / r) + PI * r * r / 2) * 1000;
}

int main() {
    ld d, l;
    ll n;
    cin >> d >> l >> n;
    ld r = d / 2.0;
    ld eps = 0.00000001;
    while(n--) {
        ld to;
        cin >> to;
        ld lx = 0, rx = 2 * r;
        while(rx - lx > eps) {
            ld mid = (lx + rx) / 2;
            if(f(mid, r, l) >= to) rx = mid;
            else lx = mid;
        }
        cout << setprecision(7) << fixed << rx << '\n';
    }
}
