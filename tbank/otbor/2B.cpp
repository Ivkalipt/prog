// #pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvll = vector<vll>;

constexpr ll INF = 1e18;

int main() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (ll & x : a) cin >> x;
    sort(all(a));
    ll l = 0, r = n - 1, mn = a[0], mx = a[n - 1];
    while (l < r) {
        while (l < n - 1 && a[l] == a[l + 1]) l++;
        while (r > 0 && a[r] == a[r - 1]) r--;
        ll cnt_l = l + 1, cnt_r = n - r;
        if (cnt_l < cnt_r) {
            if (k >= (a[l + 1] - a[l]) * cnt_l) {
                k -= (a[l + 1] - a[l]) * cnt_l;
                a[l] = a[l + 1];
            }
            else {
                a[l] += k / cnt_l;
                k = 0;
            }
            mn = a[l];
        }
        else {
            if (k >= (a[r] - a[r - 1]) * cnt_r) {
                k -= (a[r] - a[r - 1]) * cnt_r;
                a[r] = a[r - 1];
            }
            else {
                a[r] -= k / cnt_r;
                k = 0;
            }
            mx = a[r];
        }
        if (k == 0) break;
    }
    cout << max(0LL, mx - mn) << endl;



}