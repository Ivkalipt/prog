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

int main() {
    ll n;
    cin >> n;
    vll pref(n);
    cin >> pref[0];
    for(ll i = 1; i < n; i++) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    for(ll c : pref) cout << c << ' ';
    cout << '\n';
}
