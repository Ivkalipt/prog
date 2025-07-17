#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e9 + 7;

ll rec(ll a, ll b, ll &x, ll &y) {
    if (!a)
    {
        x = 0;
        y = 1;
        return b;
    }
    else
    {
        ll x1, y1;
        ll d = rec(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return d;
    }
}

int main() {
    fastio;
    ll a, b, c, x1, y1, d, x, y;
    cin >> a >> b >> c;
    d = gcd(a, b);
    if (c % d != 0) cout << "Impossible", exit(0);
    a /= d;
    b /= d;
    c /= d;
    rec(a, b, x1, y1);
    x = c * x1;
    y = c * y1;
    cout << d << ' ' << x << ' ' << y;
    cout << "\n";
    return 0;
}
