// #pragma GCC optimize ("O3")
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

ll mod = 1e9 + 7;

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    bool f = 0;
    for(ll & c : a) cin >> c;
    for(ll & c : b) cin >> c;
    sort(all(b));
    a[0] = min(a[0], b[0] - a[0]);
    for(ll c : a) cout << c << ' ';
    cout << '\n';
    for(ll c : b) cout << c << ' ';
    cout << '\n';
    for(ll i = 1; i < n; i++) {
        ll l = -1, r = m;
        while(r - l > 1) {
            ll mid = (r + l) / 2;
            if(b[mid] - a[i] >= a[i - 1]) r = mid;
            else l = mid;
        }
        if(b[r] - a[i] < a[i] && b[r] - a[i] >= a[i - 1]) a[i] = b[r] - a[i];
        else if(a[i] < a[i - 1]) a[i] = b[r] - a[i];
        if(a[i] < a[i - 1]) {
            cout << "NO\n", f = 1;
            break;
        }
    }
    if(!f) cout << "YES\n";
    for(ll c : a) cout << c << ' ';
    cout << '\n';
    for(ll c : b) cout << c << ' ';
    cout << "\n\n";
    a.clear(), b.clear();
}

int main() {
    fastio;
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
}
