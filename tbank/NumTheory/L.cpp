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

ll mini = 0;

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

void rec(ll n, ll k, vll & cur, vll & primes) {
    if(k == 1) {
        // for(ll c : cur) cout << c << ' ';
        // cout << '\n';
        ll s = 1;
        for(ll i = 0; i < cur.size(); i++) {
            s *= binpow(primes[i], cur[i] - 1);
            if(s > 1e9) return;
        }
        if(mini > s || mini == 0) mini = s;
        return;
    }
    for(ll i = 1; i * i <= k; i++) {
        if(k % i == 0) {
            if(i != 1) {
                cur.push_back(i);
                rec(n, k / i, cur, primes);
                cur.pop_back();
            }
            cur.push_back(k / i);
            rec(n, i, cur, primes);
            cur.pop_back();
        }
    }
}

vector<bool> sieve(ll n) {
    vector<bool> primes(n + 1, true);
    for(ll i = 2; i <= n; i++) {
        for(ll j = 2 * i; j <= n; j += i) {
            primes[j] = false;
        }
    }
    primes[1] = false, primes[0] = false;
    return primes;
}

int main() {
    ll n;
    cin >> n;
    vll primes;
    vector<bool> is_prime = sieve(100);
    for(ll i = 0; i < is_prime.size(); i++) {
        if(is_prime[i])
            primes.push_back(i);
    }
    vll cur;
    //for(ll i = 0; i < 100; i++) cout << primes[i] << ' ';
    //cout << '\n';
    rec(n, n, cur, primes);
    cout << mini << '\n';


}
