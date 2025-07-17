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

pll getij(ll d, ll i) {
    if(i == 1) {
        if(d == 1) return {1, 1};
        else if (d == 2) return {2, 2};
        else if (d == 3) return {2, 1};
        else return {1, 2};
    }
    ll den = 1LL << ((i << 1LL) - 2), h = 1LL << (i - 1LL);
    if(d <= den) {
        auto [x, y] = getij(d, i - 1);
        return {x, y};
    } else if (d <= 2 * den) {
        auto [x, y] = getij(d - den, i - 1);
        return {x + h, y + h};
    } else if (d <= 3 * den) {
        auto [x, y] = getij(d - 2 * den, i - 1);
        return {x + h, y};
    } else {
        auto [x, y] = getij(d - 3 * den, i - 1);
        return {x, y + h};
    }
}

ll getn(ll x, ll y, ll i) {
    if (i == 1) {
        if (x == 1 && y == 1) return 1;
        if (x == 2 && y == 2) return 2;
        if (x == 2 && y == 1) return 3;
        if (x == 1 && y == 2) return 4;
    }
    ll h = 1LL << (i - 1LL);
    ll den = 1LL << ((i << 1LL) - 2);
    if (x <= h && y <= h) {
        return getn(x, y, i - 1);
    } else if (x > h && y > h) {
        return den + getn(x - h, y - h, i - 1);
    } else if (x > h && y <= h) {
        return 2 * den + getn(x - h, y, i - 1);
    } else {
        return 3 * den + getn(x, y - h, i - 1);
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    while(q--) {
        string type;
        cin >> type;
        if(type == "->") {
            ll x, y;
            cin >> x >> y;
            cout << getn(x, y, n) << '\n';
        }
        else {
            ll d;
            cin >> d;
            pll ans = getij(d, n);
            cout << ans.F << ' ' << ans.S << '\n';
        }
    }
    
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
