#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<long long>;

ll inf = 1e16;

void solve() {
    string s, l, r;
    ll n, nn, mx = 0;
    cin >> s >> n >> l >> r;
    nn = s.size();
    for(ll i = 0; i < n; i++) {
        ll to = mx;
        for(char j = l[i]; j <= r[i]; j++) {
            ll to2 = mx;
            while(to2 < nn && s[to2] != j) to2++;
            to = max(to, to2);
        }
        mx = to + 1;
    }
    if(mx > nn) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
