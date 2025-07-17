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

int main() {
    ll n, k;
    cin >> n >> k;
    if(n & 1 || k & 1 || n - k + 2 <= 0) cout << -1 << '\n', exit(0);
    for(ll i = 0; i < k - 2; i++) {
        cout << 1 << ' ';
    }
    cout << (n - k + 2) / 2 << ' ' << (n - k + 2) / 2 << '\n';
}
