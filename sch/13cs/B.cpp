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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

ll sumstring(ll k, vector<vll> & a) {
    ll ans = 0;
    for(ll c : a[k]) ans += c;
    return ans;
}

ll sumcolom(ll k, vector<vll> & a) {
    ll ans = 0;
    for(ll i = 0; i < a.size(); i++) ans += a[i][k];
    return ans;
}

int main() {
    ll n;
    cin >> n;
    vector<vll> a(n, vll(n, 0));
    for(vll & c : a) 
        for(ll & v : c)
            cin >> v;
    set<ll> l;
    for(ll i = 0; i < n; i++) {
        l.insert(sumstring(i, a));
        l.insert(sumcolom(i, a));
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ans += a[i][i];
    }
    l.insert(ans);
    ans = 0;
    for(ll i = 0; i < n; i++) {
        ans += a[i][n - i - 1];
    }
    l.insert(ans);
    if(l.size() > 1) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
