#pragma GCC optimize ("O3")
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

ll inf = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vll a(2001, 0);
    ll mn = inf, mx = 0;
    for(ll i = 0; i < n; i++) {
        ll t;
        cin >> t;
        a[t]++;
    }
    // for(ll c : a) cout << c << ' ';
    // cout << '\n' << mn << ' ' << mx << '\n';
    for(ll i = 0; i <= 2000; i++) {
        if(a[i] == 1) {
            cout << "No\n";
            return;
        }
        if(a[i] > 0) {
            a[i + 1] += a[i] - 2;
            a[i] = 2;
        }
    }
    cout << "Yes\n";
    return;
}

int main() {
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
}
