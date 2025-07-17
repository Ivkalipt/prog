#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

ll f[45] = {0, 1};

string rec(ll n, ll l, ll r) {
    if(n == 1) return "b";
    if(n == 2) return "a";
    ll m = f[n - 1];
    if(m >= r) 
        return rec(n - 1, l, r);
    if(m < l)
        return rec(n - 2, l - m, r - m);
    return rec(n - 1, l, m) + rec(n - 2, 1, r - m);
}

int main() {
    for(ll i = 2; i < 45; i++) f[i] = f[i - 1] + f[i - 2];
    ll n, m, l;
    cin >> n >> m >> l;
    cout << rec(n, m, m + l - 1);
}
