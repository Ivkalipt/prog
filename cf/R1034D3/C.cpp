#pragma GCC optimize("Ofast,unroll-loops")
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

const int MAXN = 2e5 + 1;

void solve() {
    char str[MAXN];
    int a[MAXN], n;
    cin >> n;
    fill(str, str + n, '0');
    for (int i = 0; i < n; i++) cin >> a[i];
    int pref_min = a[0], suff_max = a[n - 1];
    str[0] = '1', str[n - 1] = '1';
    for (int i = 1; i < n; i++) {
        pref_min = min(pref_min, a[i]);
        if (pref_min == a[i]) str[i] = '1';
    }
    for (int i = n - 1; i > 0; i--) {
        suff_max = max(suff_max, a[i]);
        if (suff_max == a[i]) str[i] = '1';
    }
    for (int i = 0; i < n; i++) cout << str[i];
    cout << '\n';


}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}