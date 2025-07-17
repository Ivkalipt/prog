#pragma GCC optimize("O3,unroll-loops")
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

const ll inf = 1e18;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ai, s = 0;
    cin >> ai;
    s = k + 1;
    for(ll i = 0; i < n - 1; i++) {
        ll aj;
        cin >> aj;
        if(aj - ai < k + 1) s += aj - ai;
        else s += k + 1;
        ai = aj;
    }
    cout << s << '\n';

} 
