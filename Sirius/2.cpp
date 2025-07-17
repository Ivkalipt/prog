// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
//#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

int main() {
    ll n;
    bool flag = 0;
    cin >> n;
    vll a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 1; i < n; i++) {
        ll t = a[i];
        ll j = i - 1;
        while(j >= 0 && a[j] > t) {
            a[j+1] = a[j];
            j--;
            flag = 1;
        }
        a[j+1] = t;
        if(flag) {
            for(auto c:a) {
                cout << c << ' ';
            }
            cout << "\n";
            flag = 0;
        }
        
    }

}