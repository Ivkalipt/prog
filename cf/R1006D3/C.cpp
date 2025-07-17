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
    ll n, x;
    cin >> n >> x;
    vll ans = {0};
    ll l = 1;
    bool f = 0;
    ll anda = 0;
    while(ans.size() < n) {
        if((l & x) & (1 << (ll)(log2(l)))) {
            ans.push_back(l);
            l++;
            anda |= l;
        }
        else {
            f = 1;
            break;
        }
    }
    if(f == 0) {
        if(anda != x) {
            ans.pop_back();
            ans.push_back(x);
        }
    }
    else {
        if(ans.size() < n)
            ans.push_back(x);
        else {
            ans.pop_back();
            ans.push_back(x);
        }
        while(ans.size() < n) ans.push_back(0);
    }
    for(ll i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    // cout << f << ' ' << anda << '\n';
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
