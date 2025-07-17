#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;

const ll inf = 1e18;

int main() {
    vll a;
    while(true) {
        ll t;
        cin >> t;
        if(t == -1) break;
        else if(t == 0) {
            unordered_set<ll> se(all(a));
            ll n = se.size();
            ll cnt = 0;
            for(ll i = 0; i < n; i++) {
                if(se.count(2 * a[i])) cnt++;
            }
            cout << cnt << '\n';
            a = {};
        }
        else {
            a.push_back(t);
        }
    }
}
