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

vll a, b;
ll n, x;

tuple<ll, ll, ll> stupid() {
    // ll n, x;
    // cin >> n >> x;
    // vll a(n), b(n);
    // for (ll & c : a) cin >> c;
    // for (ll & c : b) cin >> c;
    ll ans = 0;
    ll l, r;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (x / a[i] * b[j] + x % a[i] > ans) {
                ans = x / a[i] * b[j] + x % a[i];
                l = i, r = j;
            }
        }
    }
    if (ans <= x) ans = x, l = 0, r = 0;
    return {ans, l + 1, r + 1};
}

tuple<ll, ll, ll> smart() {
    // ll n, x;
    // cin >> n >> x;
    // vll a(n), b(n);
    // for (ll & c : a) cin >> c;
    // for (ll & c : b) cin >> c;
    vll suffmax(n);
    suffmax[n - 1] = n - 1;
    ll l = 0, r = 0;
    for (ll i = n - 2; i > -1; i--) {
        if (b[i] >= b[suffmax[i + 1]])
            suffmax[i] = i;
        else
            suffmax[i] = suffmax[i + 1];
    }
    ll ans = x;
    for (ll i = 0; i < n - 1; i++) {
        ll diff = x / a[i] * b[suffmax[i + 1]] + x % a[i];
        // cout << a[i] << ' ' << b[suffmax[i + 1]] << '\n';
        if (ans < diff) {
            ans = diff;
            l = i, r = suffmax[i + 1];
        }
    }
    if (ans <= x) ans = x, l = 0, r = 0;
    return {ans, l + 1, r + 1};
    // if (ans <= x) cout << x << endl << -1 << ' ' << -1 << '\n';
    // else cout << ans << endl << l + 1 << ' ' << r + 1 << '\n';
}

mt19937 mt(time(nullptr));

void gen() {
    n = mt() % 10 + 1;
    x = mt() % 10000 + 1;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = mt() % 5001 + 1;
}

int main() {
    for (int i = 0; i < 100; i++) {
        gen();
        tuple sm = smart(), st = stupid();
        if (sm != st) {
            cout << "WA" << endl;
            cout << n << ' ' << x << endl;
            for (int j = 0; j < n; j++)
                cout << a[j] << ' ';
            cout << '\n';
            cout << get<0>(sm) << ' ' << get<1>(sm) << ' ' << get<2>(sm) << ' ' << '\n' <<
                    get<0>(st) << ' ' << get<1>(st) << ' ' << get<2>(st) << ' ' << '\n';
            break;
        }
        cout << "OK" << endl;
    }
    // tuple<ll, ll, ll> a = stupid();
    // cout << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << ' ' << '\n';
    return 0;

}
