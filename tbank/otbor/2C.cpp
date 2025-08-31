// #pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    fastio;
    ll n, t, a, b;
    cin >> n >> t >> a >> b;
    vll g(n);
    for (ll & x : g) cin >> x;
    ll l = 0, r = 0;
    ll sum_interest = 0, rem = t;
    while (rem >= a && r < n) {
        sum_interest += g[r];
        rem -= a;
        r++;
    }
    ll max_interest = sum_interest;
    while (r < n) {
        rem -= a;
        sum_interest += g[r];
        while (rem < 0) {
            sum_interest -= g[l];
            l++;
            rem = rem + a - b;
        }
        if (max_interest < sum_interest) {
            max_interest = sum_interest;
        }
        r++;
    }
    cout << max_interest << endl;


}