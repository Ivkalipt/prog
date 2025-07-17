#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

using namespace std;

struct query {
    ll l, r, d;
};

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n, 0), diff(n + 1, 0);
    for(ll & c : a) cin >> c;
    a.push_back(0);
    diff[0] = a[0];
    for(ll i = 1; i <= n; i++) diff[i] = a[i] - a[i - 1];
    vector<query> queries(m);
    for(ll i = 0; i < m; i++) {
        ll l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        queries[i] = {l, r, d};
    }
    vll diffq(m + 1, 0);
    while(k--) {
        ll x, y;
        cin >> x >> y;
        x--;
        diffq[x]++;
        diffq[y]--;
    }
    vll cnts(m);
    cnts[0] = diffq[0];
    for(ll i = 1; i < m; i++)
        cnts[i] = diffq[i] + cnts[i - 1];
    for(ll i = 0; i < m; i++) {
        ll l = queries[i].l, r = queries[i].r, d = queries[i].d * cnts[i];
        diff[l] += d;
        diff[r + 1] -= d;
    }
    vll pref(n);
    pref[0] = diff[0];
    cout << diff[0] << ' ';
    for(ll i = 1; i < n; i++) pref[i] = diff[i] + pref[i - 1], cout << pref[i] << ' ';
    cout << '\n';
}
