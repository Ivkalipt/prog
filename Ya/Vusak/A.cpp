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

int main() {
    ll n, m;
    cin >> n >> m;
    ll cnt = 0, s = 0;
    while(n--) {
        ll t;
        cin >> t;
        s += t;
        if(s == m) {
            cnt++;
            s = 0;
        }
        else {
            if(s % m == 0) cnt++;
            s %= m;
        }
    }
    cout << cnt << '\n';
}
