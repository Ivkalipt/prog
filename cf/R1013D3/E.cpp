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
#define rall(a) a.rbegin(), a.rend()

vll primes;

void sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    for (ll i = 2; i <= n; i++)
        if (is_prime[i])
            for (ll j = 2 * i; j <= n; j += i)
                is_prime[j] = false;
    for(ll i = 1; i <= n; i++) {
        if(is_prime[i]) primes.push_back(i);
    }
}

void solve() {
    ll n;
    cin >> n;
    ll cnt = 0;
    for(ll i = 1; i < primes.size() && primes[i] <= n; i++) {
        cnt += n / primes[i];
        // cout << n / primes[i] << ' ' << primes[i] << '\n';
    }
    cout << cnt << '\n';
}

int main() {
    ll t;
    cin >> t;
    sieve(1e7 + 1);
    while(t--) solve();
}
