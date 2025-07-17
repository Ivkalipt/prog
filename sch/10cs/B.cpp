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

constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vll cnt(101, 0);
    for(ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        cnt[t]++;
    }
    cout << *max_element(all(cnt)) << '\n';
}
