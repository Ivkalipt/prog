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

vll factorize(ll x) {
    vll factors;
    for (int i = 2; i * i <= x; i++)
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }

    if (x > 1)
        factors.push_back(x);
    return factors;
}

int main() {
    fastio;
    ll n, k = 1;
    cin >> n;
    vll f(44);
    for(ll i = 1; i <= n; i++)
        for(ll c : factorize(i))
            f[c]++;
    for(ll c : f)
        k *= (c+1);
    cout << k << '\n';
    return 0;
}

