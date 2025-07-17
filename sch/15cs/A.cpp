#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e18;

int main() {
    ll n;
    cin >> n;
    vll a(n);
    vll ans;
    for(ll & c : a) cin >> c;
    for(ll i = 0; i < n; i++) {
        bool f = 1;
        for(ll j = 0; j < n; j++) {
            if(i != j && a[i] % a[j] == 0) {
                f = 0;
                break;
            }
        }
        if(f) cout << a[i] << ' ';
    }
}
