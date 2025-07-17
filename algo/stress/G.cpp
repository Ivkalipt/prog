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

struct node {
    ll sum, pref, suf, seg;
};

inline node one(ll x) { return {x, max(0LL, x), max(0LL, x), max(0LL, x) }; };

node merge(node a, node b) {
    node c;
    c.sum = a.sum + b.sum;
    c.pref = max(a.pref, a.sum + b.pref);
    c.suf = max(b.suf, a.suf + b.sum);
    c.seg = max({a.seg, b.seg, a.suf + b.pref});
    return c;
}

node divide_et_impera(vll a) {
    if (a.size() == 1) return one(a[0]);
    ll m = a.size() >> 1;
    return merge(
        divide_et_impera(vll(a.begin(), a.begin() + m)),
        divide_et_impera(vll(a.begin() + m, a.end()))
    );
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    ll l = 0, r = 0, maxL = 0, maxR = 0, maxVal = a[0], sum = 0, pos = -1;
    for(ll i = 0; i < n; i++) {
        sum += a[i];
        if(sum > maxVal) {
            maxVal = sum;
            maxR = i;
            maxL = pos + 1;
        }

        if(sum < 0) {
            sum = 0;
            pos = i;
        }
    }
    cout << maxL + 1 << ' ' << maxR + 1 << ' ' << maxVal << '\n';
}