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

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[1] = false;
    for(ll i = 2; i <= n; i++) {
        for(ll j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
    return is_prime;

}

int main() {
    ll a, b;
    cin >> a >> b;
    vector<bool> is_prime = sieve(b);
    for(ll i = a; i <= b; i++) {
        if(is_prime[i]) cout << i << ' ';
    }
}
