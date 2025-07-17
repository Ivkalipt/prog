// #pragma GCC optimize ("O3, unroll-all-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

ll inf = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    map<ll, ll> dt, dt1;
    for(ll & c : a) cin >> c, dt[c]++;
    ll bs = a.size() - set<ll>(all(a)).size();
    ll l = 0, r = 0, maxL = 0, maxR = 0, maxVal = bs, pos = -1;
    ll delta = 0;
    for(ll i = 0; i < n; i++) {
        dt1[a[i]]++;
        if(dt1[a[i]] == dt[a[i]]) delta++;
        if(delta - (i - pos - 2) > maxVal) {
            maxVal = delta - (i - pos - 2);
            maxR = i;
            maxL = pos + 1;
        }
        if(delta - (i - pos - 2) < 0) {
            while(delta - (i - pos - 2) < 0 && pos != i) {
                if(dt1[a[pos]] == dt[a[pos]]) delta--;
                dt1[a[pos]]--;
                pos++;
            }
        }
        // cout << delta << '\n';
    }
    cout << maxL << ' ' << maxR << ' ' << maxVal << '\n'; 
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
