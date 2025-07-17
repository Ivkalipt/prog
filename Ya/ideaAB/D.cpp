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

int main() {
    ll n, x, l = 0, oper = 0;
    cin >> n >> x;
    vll q(n);
    for(ll & c : q) cin >> c;
    vll pref(n);
    pref[0] = (q[0] >= x);
    for(ll i = 1; i < n; i++) pref[i] = pref[i - 1] + (q[i] >= x);
    ll m;
    cin >> m;
    while(m--) {
        short type;
        cin >> type;
        if(type == 1) {
            ll a;
            cin >> a;
            q.push_back(a);
            pref.push_back((pref.back() + (a >= x)));
        }
        else if(type == 2) {
            if(q[l] >= x) oper--;
            l++;
        }
        else if(type == 3) {
            ll i;
            cin >> i;
            cout << (i - 1 >= 0 ? pref[l + i - 1] + oper : 0) << '\n';
        }
    }
    /*for(ll c : pref) cout << c << ' ';
    cout << '\n';
    for(ll c : q) cout << c << ' ';
    cout << '\n';*/

}
