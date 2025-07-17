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
    ll n, k, cnt = 0, mini = inf;
    cin >> n >> k;
    vll a = factorize(k);
    unordered_map<ll, ll> cnt2;
    for(ll i = 0; i < a.size(); i++) {
        if(cnt2.count(a[i])) cnt2[a[i]]++;
        else cnt2[a[i]] = 1;
    }
    for(pll c : cnt2) {
        ll l = c.F, s = 0;
        while(l <= n) {
            s += n / l;
            l *= c.F;
        }
        mini = min(mini, s / c.S);
    }
    cout << mini << '\n';

}
