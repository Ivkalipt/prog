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
    ll n, k, l, r;
    cin >> n;
    vll A(n+1), S(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> A[i];
    }
    S[0] = 0;
    for(ll i = 1; i <= n; i++) {
        S[i] = S[i-1] + A[i];
    }
    cin >> k;
    for(ll i = 0; i < k; i++) {
        cin >> l >> r;
        cout << S[r]-S[l-1] << " ";
    }

}