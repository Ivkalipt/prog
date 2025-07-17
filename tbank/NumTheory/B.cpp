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

vll factorize(ll x) {
    vll ds;
    for (ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            ds.push_back(i);
            x /= i;
        }
    }

    if (x > 1) {
        ds.push_back(x);
    }

    return ds;
}

int main() {
    ll n;
    cin >> n;
    vll ds = factorize(n);
    map<ll, ll> a;
    for(ll i = 0; i < ds.size(); i++) {
        if(a.count(ds[i]))
            a[ds[i]]++;
        else
            a[ds[i]] = 1;
    }
    
    for(auto c : a) {
        cout << c.F;
        if(c.S != 1) cout << '^' << c.S;
        if(c.F != ds.back()) cout << '*';
    }
}

