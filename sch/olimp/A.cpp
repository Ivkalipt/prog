#pragma gcc optimize ("o3,unroll-loops")
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

vector<bool> sieve(ll n) {
    vector<bool> is_prime(n + 1, true);
    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            for (ll j = 2*i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime; 
}

int main() {
  ll n;
  cin >> n;
  vector<bool> primes = sieve(n);
  for(ll i = 2; i < n; i++) {
    if(primes[i]) {
      cout << i << ' ';
    }
  }
}
