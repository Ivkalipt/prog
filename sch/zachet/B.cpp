#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e9 + 7;

int main() {
    ll a, b,k = 0;
    cin >> a >> b;
    while(a != b && k < 50) {
        if(a > b) {
            a -= b;
            b = 2 * b;
        }
        else {
            b -= a;
            a = 2 * a;
        }
        k++;

    }
    cout << k << '\n';
}
