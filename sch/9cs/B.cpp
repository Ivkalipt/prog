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

constexpr ll INF = 1e18;

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}



int main() {
    ll n;
    cin >> n;
    unordered_set<ll> d1, d2;
    unordered_set<ll> ans;
    ll t;
    cin >> t;
    d1 = {t};
    ans.insert(t);
    for(ll i = 1; i < n; i++) {
        ll t;
        cin >> t;
        for(ll c : d1) d2.insert(gcd(c, t));
        d2.insert(t);
        for(ll c : d2) ans.insert(c);
        d1 = d2;
        d2.clear();
    }
    cout << ans.size() << '\n';
}

