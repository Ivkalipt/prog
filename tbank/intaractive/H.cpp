#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

ll interact(ll m) {
    cout << "? " << m << endl;
    ll res; cin >> res;
    return res;
}

void solve() {
    ll n;
    cin >> n;
    ll l = 1, r = n;
    while(l != r - 1) {
        ll m = (l + r) >> 1;
        ll res = interact(m);
        if(res == 0) r = m;
        else l = m;
    }
    cout << "! " << l << endl;
}

int main() {
    fflush(stdout);
    solve();
    return 0;
}
