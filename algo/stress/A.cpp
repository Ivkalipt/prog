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

const ll maxn = 1e5;

vector<ld> a;
ll n;

pll stupid() {
    /*ll n;
    cin >> n;
    vector<ld> a(n);
    for (ld & c : a) cin >> c;*/
    ld ans = 0;
    ll l, r;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            if (a[j] / a[i] > ans) {
                ans = a[j] / a[i];
                l = i, r = j;
            }
        }
    }
    if (ans <= 1) return {0, 0};
    return {l + 1, r + 1};
}

pll smart() {
    /*ll n;
    cin >> n;
    vector<ld> a(n);
    for (ld & c : a) cin >> c;*/
    vll suffmax(n);
    suffmax[n - 1] = n - 1;
    ll l, r;
    for (ll i = n - 2; i > -1; i--) {
        if (a[i] > a[suffmax[i + 1]])
            suffmax[i] = i;
        else
            suffmax[i] = suffmax[i + 1];
    }
    ld ans = 0;
    for (ll i = 0; i < n - 1; i++) {
        ld diff = a[suffmax[i + 1]] / a[i];
        if (ans < diff) {
            ans = diff;
            l = i, r = suffmax[i + 1];
        }
    }
    /*for (ll c : suffmax) cout << c << ' ';
    cout << '\n';*/
    if (ans <= 1) return {0, 0};
    return {l + 1, r + 1};
}

mt19937 mt(time(nullptr));

void gen() {
    n = mt() % 10 + 1;
    a.resize(n);
    for (int i = 0; i < n; i++)
        a[i] = mt() % 5001 + 1;
}

int main() {
    for (int i = 0; i < 100; i++) {
        gen();
        pll sm = smart(), st = stupid();
        if (sm != st) {
            cout << "WA" << endl;
            cout << n << endl;
            for (int j = 0; j < n; j++)
                cout << a[j] << ' ';
            cout << '\n';
            cout << sm.F << ' ' << sm.S << ' ' << st.F << ' ' << st.S << '\n';
            break;
        }
        cout << "OK" << endl;
    }
    /*pll a = smart();
    cout << a.F << ' ' << a.S << '\n';*/
    return 0;

}