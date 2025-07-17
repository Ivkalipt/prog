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

const ll inf = 1e18, maxn = 6 * 1e6;

vector<bool> is_prime(maxn, true);
vll primes;

void sieve() {
    for (ll i = 2; i <= maxn; i++)
        if (is_prime[i])
            for (ll j = 2 * i; j <= maxn; j += i)
                is_prime[j] = false;
    for (ll i = 2; i <= maxn; i++) {
        if(is_prime[i]) primes.push_back(i);
    }
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    sort(all(a));
    ll l = 0, s = 0;
    for(ll i = 0; i < n; i++) {

        cout << a[i] << ' ' << primes[l] << ' ' << l << '\n';
        if(primes[l] <= a[i]) s += a[i] - primes[l], l++;
        else if(primes[l] - a[i] <= s) s -= primes[l] - a[i], l++;
    }
    cout << n - l << '\n';

}

int main() {
    ll t;
    cin >> t;
    sieve();
    /*for(ll i = 0; i < 40; i++) {
        cout << primes[i] << ' ';
    }
    cout << primes.size() << '\n';*/
    while(t--) solve();
}
