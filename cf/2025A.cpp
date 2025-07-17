#pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

const ll inf = 1e9 + 1;

int main() {
    ll t;
    cin >> t;
    vll n(t), k(t);
    for(ll & c : n) cin >> c;
    for(ll & c : k) cin >> c;
    for(ll _ = 0; _ < t; _++) {
        vvll C(n[_] + 1, vll(n[_] + 1, 0));
        for(ll i = 0; i <= n[_]; i++) {
            C[i][0] = 1;
            C[i][i] = 1;
            for(ll j = 1; j < i; j++) {
                C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % inf;
            }
        }
        cout << C[n[_]][k[_]] << '\n';
    }
}
