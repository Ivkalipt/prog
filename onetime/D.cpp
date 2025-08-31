#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 2e5;

void solve() {
    ll x, y, r;
    cin >> x >> y >> r;
    ll cnt = 1;
    bool f = 0;
    ll l_y = abs(x), l_x = abs(y);
    ld ldx = (ld)x, ldy = (ld)y, ldr = (ld)r;
    if (l_y < r) cnt++;
    if (l_y <= r) f = 1;
    if (l_x < r) cnt++;
    if (l_x <= r) f = 1;
    if (sqrtl(x * x + y * y) < r) cnt++;
    if (sqrtl(x * x + y * y) <= r) f = 1;
    cout << cnt + f << '\n';


    /*if (x > 0 && y > 0) {
        if (x - r < 0) cnt++;
        if (y - r < 0) cnt++;
        ld ldx = (ld)x, ldy = (ld)y, ldr = (ld)r;
        if (ldx - ldr / sqrtl(2) < 0 && ldy - ldr / sqrtl(2) < 0) cnt++;
    }
    if (x < 0 && y > 0) {
        if (x + r > 0) cnt++;
        if (y - r < 0) cnt++;
        ld ldx = (ld)x, ldy = (ld)y, ldr = (ld)r;
        if (ldx + ldr / sqrtl(2) > 0 && ldy - ldr / sqrtl(2) < 0) cnt++;
    }
    if (x > 0 && y < 0) {
        if (x - r < 0) cnt++;
        if (y + r > 0) cnt++;
        ld ldx = (ld)x, ldy = (ld)y, ldr = (ld)r;
        if (ldx - ldr / sqrtl(2) < 0 && ldy + ldr / sqrtl(2) > 0) cnt++;
    }
    if (x < 0 && y < 0) {
        if (x + r > 0) cnt++;
        if (y + r > 0) cnt++;
        ld ldx = (ld)x, ldy = (ld)y, ldr = (ld)r;
        if (ldx + ldr / sqrtl(2) > 0 && ldy + ldr / sqrtl(2) > 0) cnt++;
    }*/

}

int main() {
    fastio; // убрать на интерактивках
    solve();
    return 0;
}