// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
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

struct point {ll cord, type, num;};

int main() {
    ll n, m, l, r, p;
    cin >> n >> m;
    vector<point> a;
    for(ll i = 0; i < n; i++) cin >> l >> r, a.push_back({min(l, r), 0, -1}), a.push_back({max(l, r), 2, -1});
    for(ll i = 0; i < m; i++) cin >> p, a.push_back({p, 1, i});
    sort(all(a), [](point x, point y) { 
        return make_pair(x.cord, x.type) < make_pair(y.cord, y.type);
    });
    ll cnt = 0;
    vll b(m);
    for(point c : a) {
        if(!c.type) cnt++;
        else if(c.type == 1) b[c.num] = cnt;
        else cnt--;
    }
    for(ll c : b) cout << c << ' ';
    cout << '\n';
}
