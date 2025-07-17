#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pair<ll, ll>>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

ll wt(ll i, ll j) {
    i++, j++;
    return (179 * i + 719 * j) % 1000 - 500;
}

int main() {
    ll n;
    cin >> n;
    vector<vpll> g(n);
    vll d(n, inf);
    d[0] = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = i + 1; j < n; j++) {
            if(d[j] > d[i] + wt(i, j) && d[i] != inf) {
                d[j] = d[i] + wt(i, j);
            }
        }
    }
    cout << d[n - 1] << '\n';
}
