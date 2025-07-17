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

const ll inf = 1e18;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    if((c - 2 * b + a) % 3 == 0 && (c - 2 * b + a) >= 0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
