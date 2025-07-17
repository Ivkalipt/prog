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
    ll n, k, t = 0;
    cin >> n >> k;
    vll a(n);
    for(ll i = 1; i <= n; i++) {
        a[i-1] = i;
    }
    
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n-1; j++) {
            if(a[j] < a[j+1] and t < k) {
                swap(a[j], a[j+1]);
                t++;
            }
            
        }
    }
    for(auto c:a) {
	cout << c << ' ';
    }
    
}
