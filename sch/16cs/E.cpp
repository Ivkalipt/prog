#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<long long>;

struct fraction {
    ll num, den;
    ld div;
};

bool operator < (const fraction & x, const fraction & y) {
    return x.div < y.div;
}

bool operator == (const fraction & x, const fraction & y) {
    return x.num == y.num && x.den == y.den;
}

int main() {
    ll n;
    cin >> n;
    vector<fraction> frac;
    for(ll i = 1; i <= n; i++) {
        for(ll j = i + 1; j <= n; j++) {
            frac.push_back({i / gcd(i, j), j / gcd(i, j),  (ld)i / j});
        }
    }
    sort(all(frac));
    frac.erase(unique(all(frac)), frac.end());
    for(fraction c : frac) {
        cout << c.num << '/' << c.den << '\n';
    }
}
