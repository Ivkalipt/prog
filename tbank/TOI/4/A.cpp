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

struct el {
    string s;
    ll l, r, cntH, cntG;
};

int main() {
    ll n;
    cin >> n;
    string h;
    cin >> h;
    vll a(n);
    for(ll & c : a) 
        cin >> c;
    vector<el> b(n, {"", 0, 0, 0, 0});
    ll cntH = 0, cntG = 0;
    for(char c : h) {
        if(c == 'H') cntH++;
        else cntG++;
    }
    for(ll i = 0; i < n; i++) {
        b[i].s = h.substr(i, a[i] - i);
        b[i].l = i;
        b[i].r = a[i] - 1;
        for(char c : b[i].s) {
            if(c == 'H') b[i].cntH++;
            else b[i].cntG++;
        }
    }
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(b[i].cntH == cntH || b[i].cntG == cntG) {
            for(ll j = 0; j < n; j++) {
                if(b[j].l <= i && b[j].r >= i && i != j) {
                    cnt++;
                    // cout << i << ' ';
                }
            }
        }
    }
    /*for(el c : b) {
        cout << c.s << ' ' << c.l << ' ' << c.r << ' ' << c.cntH << ' ' << c.cntG << '\n';
    }*/
    cout << cnt << '\n';


    
}
