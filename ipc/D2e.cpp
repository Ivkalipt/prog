// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

vector<int> factorize(int x) {
    vector<int> factors;

    for (int i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    if (x > 1) {
        factors.push_back(x);
    }

    return factors;
}

int main() {
    fastio;
    ll n;
    cin >> n;
    v(int) a = factorize(n);
    for(ll i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i != a.size()-1) cout << "*";
        
    }
    cout << "\n";
    return 0;
}