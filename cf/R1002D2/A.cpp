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
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vll a(n), b(n);
        for(ll & c : a) cin >> c;
        for(ll & c : b) cin >> c;
        set<ll> sums;
        for(ll c : a) {
            for(ll v : b) {
                sums.insert(c + v);
            }
        }
        if(sums.size() < 3) cout << "NO\n";
        else cout << "YES\n";
    }
}

