#include <iomanip>
#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

const ll inf = 1e18;

int main() {
    ll n;
    ld sum = 0;
    cin >> n;
    vector<ld> a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ll sr = ((ld)sum / (ld)n) * 100;
    for(ld c : a) cout << fixed << setprecision(2) << (c * 100 - (ld)sr) / 100 << ' ';
    cout << '\n';
}
