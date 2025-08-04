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

ll powByMod(ll a, ll n, ll mod) {
    if(n == 0) return 1;
    if (n % 2 == 0) return powByMod((a * a) % mod, n / 2, mod);
    return (a * powByMod(a, n - 1, mod)) % mod;
}

int main() {
    ll a, p;
    cin >> a >> p;
    cout << powByMod(a, p - 2, p) << '\n';
}
