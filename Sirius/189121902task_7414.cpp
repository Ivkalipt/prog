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
    ll a, b, d, k, x1, x2;
    cin >> a >> b >> d;
    if(abs(a+b)%2==0) {
        cout << (a+b)/2;
    }
    else {
        x1 = ceil((a+b)/d)*d;
        x2 = x1 - d;
        cout << x1 << x2; //(abs(x1-ceil((a+b)/2))>abs(x2-floor((a+b)/2))?floor((a+b)/2):ceil((a+b)/2));
    }
}