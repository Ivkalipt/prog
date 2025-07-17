#pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const ll inf = 1e9 + 7;

struct per {
    ld p;
    ll ind1, ind2;
};

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    ll n, c, x, y, x1, y1, x2, y2;
    cin >> n;
    vector<per> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> c;
        ld p = 0;
        for(ll j = 0; j < c; j++) {
            cin >> x >> y;
            if(j == 0) {
                x1 = x, y1 = y;
                x2 = x, y2 = y;
            }
            else {
                p += dist((ld)x, (ld)y, (ld)x1, (ld)y1);
                x1 = x, y1 = y;
            }
            if(j == c - 1) {
                p += dist((ld)x, (ld)y, (ld)x2, (ld)y2);
            }
        }
        a[i] = {p, i, 0};
    }
    sort(all(a), [](per a1, per b1) {
            return a1.p > b1.p;
            });
    for(ll i = 0; i < n; i++) {
        a[i] = {a[i].p, a[i].ind1, i};
    }
    sort(all(a), [](per a1, per b1) {
            return a1.ind1 < b1.ind1;
            });
    for(ll i = 0; i < n; i++) {
        cout << a[i].ind2 << ' ';
    }

    cout << '\n';
}
