// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

vector<ll> factorize(ll x) {
    vector<ll> factors;
    ll n = x;
    ll p = 2;
    while(n != 1) {
        if(n % p != 0) {
            p++;
        }
        else {
            n /= p;
            factors.push_back(p);
        }
    }

    return factors;
}

int main() {
    ll n, t = 1;
    cin >> n;
    vll a = factorize(n);
    /*for(ll c : a) {
        cout << c << '\n';
    }*/
    ll k = 1;
    a.push_back(0);
    for(ll i = 1; i < a.size(); i++) {
        if(a[i] != a[i - 1]) {
            //cout << a[i - 1] << ' ' << a[i] << '\n';
            if(k % 2 != 0) {
                t *= a[i - 1];
                //cout << a[i - 1];
                k = 0;
            }
        }
        k++;
        //cout << k << '\n';
    }
    cout << t << '\n';
}

/*  function getMultipliers(number: int): vector<int>
      // сюда складываем множители
      result = vector<int>
      // число, у которого осталось найти множители
      curNum = number
       // число, на которое пытаемся делить
      probe = 2
      while curNum ≠

 1
          if curNum mod probe ≠

0
              // проверены все множители из [2; probe]
              probe++
          else
              // делим пока делится
              curNum /= probe
              result += [probe]
       return result*/
