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

int main(){
    ll w, h, n;
    cin >> w >> h >> n;
    ll l = 0, r = max(w, h) * n;
    while(r - l > 1) {
        ll mid = (r + l) / 2;
        if((mid / w) * (mid / h) >= n) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << r << '\n';
}
