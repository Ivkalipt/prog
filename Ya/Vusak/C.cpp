#include <utility>
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

int main(){
    fastio; 
    ll n;
    cin >> n;

    vll a(n), b(n);
    for(ll & c : a) cin >> c;
    for(ll & c : b) cin >> c;

    unordered_map<ll, ll> cnt1, cnt2;
    cnt1.reserve(n), cnt2.reserve(n);
    for(ll c : a) cnt1[c]++;
    for(ll c : b) cnt2[c]++;
    vll c;
    c.reserve(n);
    for(pll p : cnt1){
        ll ac, bc;
        ac = p.S;
        bc = (cnt2.count(p.F) ? cnt2[p.F] : 0);
        if(ac != bc) {
            c.push_back(p.F);
        }
    }
    for(pll p : cnt2) {
        ll x = p.F;
        if(!cnt1.count(x)){ 
            c.push_back(x);
        }
    }

    sort(all(c));
    c.erase(unique(all(c)), c.end());
    if(c.size() == 0) cout << 0 << "\n", exit(0);
    else if(c.size() == 2) {
        ll x1 = (cnt1.count(c[0]) ? cnt1[c[0]] : 0);
        ll x2 = (cnt1.count(c[1]) ? cnt1[c[1]] : 0);
        ll y1 = (cnt2.count(c[0]) ? cnt2[c[0]] : 0);
        ll y2 = (cnt2.count(c[1]) ? cnt2[c[1]] : 0);
        if(x1 == y2 && x2 == y1){
            cout << "1\n";
            return 0;
        }
        else {
            cout << "-1\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
