#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll & x : a) cin >> x;
    ll l = 0, r = n - 1;
    string ans = "";
    while (l != n && r != 0) {
        if (a[l] < a[l + 1] && a[l + 1] < a[l + 2] && a[l + 2] < a[l + 3] && a[l + 3] < a[l + 4]) {
            while (a[l] < a[r] && a[r] < a[l + 1]) l++, ans += 'L';
            ans += 'R';
            r--;
        }
        if (a[l] > a[l + 1] && a[l + 1] > a[l + 2] && a[l + 2] > a[l + 3] && a[l + 3] > a[l + 4]) {
            while (a[l] > a[r] && a[r] > a[l + 1]) l++, ans += 'L';
            ans += 'R';
            r--;
        }
    }
    cout << ans << '\n';
}

int main() { ll t; cin >> t; while (t--) solve(); }