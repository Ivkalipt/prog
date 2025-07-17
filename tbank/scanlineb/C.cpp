#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

struct Seg {
    ll cord, type, ind;
};

int main() {
    ll n;
    cin >> n;
    vector<Seg> segs;
    vll ans(n);
    ll notopens = n, closes = 0;
    for(ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        segs.push_back({a, 1, i});
        segs.push_back({b, 0, i});
    }
    sort(all(segs), [](Seg a, Seg b) {
            return a.cord < b.cord || (a.cord == b.cord && a.type > b.type);
            });
    for(Seg & c : segs) {
        if(c.type) {
            ans[c.ind] = closes;
            notopens--;
        }
        else {
            ans[c.ind] += notopens;
            closes++;
        }
    }
    for(ll c : ans) cout << n - 1 - c << '\n';
    


}
