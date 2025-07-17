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

ll binpow(ll a, ll n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return binpow(a, n - 1) * a;
    else {
        ll b = binpow(a, n / 2);
        return b * b;
    }
}

map<ll, ll> factorize(ll x) {
    map<ll, ll> f;
    while(x % 2 == 0) f[2]++, x /= 2;
    for(ll i = 3; i * i <= x; i += 2)
        while(x % i == 0) f[i]++, x /= i;
    if (x != 1) f[x]++;
    return f;
}

int main() {
    ll a, k = 1, n = 1, maxalph = 0, l = 0;
    cin >> a;
    map<ll, ll> fct = factorize(a);
    vll fct2(fct.size());
    for(auto c : fct) {
        if(c.S > maxalph) maxalph = c.S;
        fct2[l] = c.F;
        l++;
    }
    for(ll c : fct2) n *= c;
    while(binpow(n * k, n * k) % a != 0 && n * k < maxalph) k++;
    cout << n * k << '\n';
}
