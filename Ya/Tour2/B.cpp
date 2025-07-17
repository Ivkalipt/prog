#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second

ll inf = 1e16;
ll cnt = 0;

void rec(ll pos, vll & cur, vll & a) {
    if(pos == a.size()) {
        map<ll, ll> cntr;
        for(ll i = 0; i < cur.size(); i++) {
            if(cntr.count(cur[i])) cntr[cur[i]]++;
            else cntr[cur[i]] = 1;
        }
        ll s = 0;
        for(pll c : cntr) {
            if(s == 0) s = c.S;
            if(c.S != s) return; 
        }
        cnt++;
        return;
    }
    rec(pos + 1, cur, a);
    cur.push_back(a[pos]);
    rec(pos + 1, cur, a);
    cur.pop_back();
}

int main() {
    ll n;
    cin >> n;
    vll a(n), cur;
    for(ll & c : a) cin >> c;
    rec(0, cur, a);
    cout << cnt << '\n';
}
