#pragma GCC optimize("O3,unroll-loops")
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

const ll inf = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vll a(n), b(m);
    map<ll, ll> cb;
    for(ll & c : a) cin >> c;
    for(ll & c : b) cin >> c, cb[c]++;
    sort(all(a));
    for(ll i = 0; i < n; i++) {
        if(cb.count(a[i])) {
            cb[a[i]]--;
            if(cb[a[i]] == 0)
                cb.erase(a[i]);
            a[i] = 0;

        }
        else if(i != n - 1 && abs(a[i] - a[i + 1]) <= 1) {
            a[i + 1] += a[i];
            a[i] = 0;
        }
    }
    for(ll c : a)
        if(c != 0) {
            cout << "No1\n";
            return;
        }
    for(pll c : cb) {
        if(c.S != 0) {
            cout << "No\n";
            return;

        }
    }
    cout << "Yes\n";
            
    
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
