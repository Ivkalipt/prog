// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define F first
#define S second

using namespace std;

int main() {
    ll t, a, b, k, m, tmp1, tmp2;
    ld temp, h1, h2, v1, v2, D;
    cin >> t;
    for(ll _ = 0; _ < t; _++) {
        cin >> a >> b >> k >> m;
        D = k*k+4*k+4-4*m;
        if(D < 0) {
            cout << -1;
            return 0;
        }
        else {
            if(sqrt(D)-(ll)sqrt(D) == 0) {
                h1 = (k+sqrt(D))/2;
                h2 = (k-sqrt(D))/2;
                v1 = k - h1;
                v2 = k - h2;
                
            }
            else {
                cout << -1;
            }
        }
        
    }

}