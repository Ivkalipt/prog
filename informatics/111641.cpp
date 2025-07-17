#pragma GCC optimize ("O3,unroll-loops")
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
    ll n, maxi, maxj, s, maxsum = -10e4-7;
    cin >> n;
    vll A(n+1, 0), S(n+1, 0);
    for(ll i = 1; i <= n; i++) {
        cin >> A[i];
        S[i] = A[i]+S[i-1];
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = i; j <= n; j++) {
            s = S[j] - S[i-1];
            if(s > maxsum) {
                maxi = i;
                maxj = j;
                maxsum = s;
            }
        }
    }
    cout << maxi << " " << maxj << " " << maxsum;

}