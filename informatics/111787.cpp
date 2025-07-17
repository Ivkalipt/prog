// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define F first
#define S second

using namespace std;

int main() {
    ll n, m, t;
    cin >> n >> m;
    vvll A(n+1, vll(m+1, 0)), S(n+1, vll(m+1, 0));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> A[i+1][j+1];
        }
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            S[i][j] = S[i][j-1] + S[i-1][j] - S[i-1][j-1] + A[i][j];
        }
    }
    for(ll i = 0; i <= n; i++) {
        for(ll j = 0; j <= m; j++) {
            cout << S[i][j] << " ";
        }
        cout << "\n";
    }

}