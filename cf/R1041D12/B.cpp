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

constexpr ll INF = 4e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector pref(n + 1, 0), suf(n + 1, 0);
    pref[0] = 1;
    for (ll i = 1; i <= n; i++) {
        pref[i] = pref[i - 1];
        if (s[i - 1] == '#') pref[i] = i + 1;
    }
    suf[n] = 1;
    for (ll i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (s[i] == '#') suf[i] = n - i + 1;
    }
    if (m == 1 or m == n) {
        cout << 1 << "\n";
        return;
    }
    bool f1 = 0, f2 = 0;
    if (s[m - 2] == '.') f1 = 1;
    if (s[m] == '.') f2 = 1;
    if (f1 && f2) {
        if (pref[m] < suf[m - 1]) pref[m] = m;
        else suf[m - 1] = n - m + 1;
    }
    else if (f1) pref[m] = m;
    else if (f2) suf[m - 1] = n - m + 1;
    cout << min(pref[m], suf[m - 1]) << "\n";
}

int main() {fastio; ll t; cin >> t; while (t--) solve();}