#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    a.push_back(0);
    stack<pll> curh;
    curh.push({0, -1});
    ll Ss = 0;
    for(ll i = 0; i <= n; i++) {
        ll k = i + 1;
        while(curh.top().S >= a[i]) {
            k = curh.top().F; 
            ll h = curh.top().S;
            curh.pop();
            if(Ss < h * (i - k + 1)) Ss = h * (i - k + 1);
            // cout << Ss << ' ' << h << ' ' << i << ' ' << k << ' ' << a[i] << ' ' << '\n';
        }
        curh.push({k, a[i]});
    }
    cout << Ss << '\n';
}
