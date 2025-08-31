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

constexpr ll INF = 1e18;

int main() {
    ll n, k;
    cin >> n >> k;
    vll a(n + 1), p(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    ll ans = 0;
    if (k == 2) {
        for (ll i = 1; i < n; i++) {
            ll l = p[i], r = p[n] - p[i];
            ans = max(ans, max(l, r) - min(l, r));
            //cout << l << ' ' << r << '\n';
        }
        cout << ans << endl;
        return 0;
    }
    vll prefmin(n + 1, INF), suffmin(n + 2, INF), prefmax(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        prefmin[i] = min(prefmin[i - 1], a[i]);
        prefmax[i] = max(prefmax[i - 1], a[i]);
    }
    for (ll i = n; i > 0; i--)
        suffmin[i] = min(suffmin[i + 1], a[i]);
    ll sum = 0;
    for (ll i = 1; i <= k; i++) {
        ans = max(ans, p[n - k + i] - p[i - 1] - min(prefmin[i - 1], suffmin[n - k + i + 1]));
        // cout << p[n - k + i] - p[i - 1] << ' ' << min(prefmin[i - 1], suffmin[n - k + i + 1]) << ' ' << i - 1 << ' ' << n - k + i + 1 << '\n';
    }
    for (ll i = 1; i <= n - k + 1; i++) {
        ans = max(ans, p[i] - a[i + 1]);
        // cout << p[i] - a[i + 1] << ' ' << i << ' ' << a[i + 1] << '\n';
    }
    for (ll i = n; i >= k; i--) {
        ans = max(ans, p[n] - p [i - 1] - a[i - 1]);
        // cout << p[n] - p[i - 1] - a[i - 1] << ' ' << i << ' ' << a[i - 1] << '\n';
    }
    cout << ans << endl;

    
}