#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(a) a.begin(), a.end()
#define F first
#define S second

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;

string stupid() {
    stringstream out;
    ll n;
    cin >> n;
    vll pref(n + 1), a(n);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i - 1];
        pref[i] = pref[i - 1] + a[i - 1];
    }
    ll ans = 0, l = 0, r = 0;
    return "";
}

string smart() {
    stringstream out;
    ll n;
    cin >> n;
    vll pref(n + 1), a(n);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i - 1];
        pref[i] = ((pref[i - 1] + a[i - 1]) % 3 + 3) % 3;
    }
    ll ff[] = {-1, -1, -1};
    ll max_seg = 0, l = 0, r = 0;
    for (ll i = 0; i <= n; i++) {
        if (ff[pref[i]] == -1) { ff[pref[i]] = i; continue; }
        ll diff = i - ff[pref[i]];
        if (diff > max_seg || (diff == max_seg && l > ff[pref[i]] + 1)) {
            max_seg = diff;
            l = ff[pref[i]] + 1, r = i;
        }
    }
    if (max_seg == 0) out << -1 << '\n';
    else out << l << ' ' << r << '\n';
    return out.str();
}

int main() {
    cout << smart();
}