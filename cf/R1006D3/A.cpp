#pragma GCC optimize ("Ofast")

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
    ll n, k, p;
    cin >> n >> k >> p;
    k = abs(k);
    ll ans = (k + p - 1) / p;
    if(ans > n) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
