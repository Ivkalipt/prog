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

ll inf = 1e9 + 7;

int main() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for(ll & c : a) cin >> c;
    ll sum = 0;
    for(ll i = 0; i < k; i++) sum += a[i];
    ll maxi = sum, l = 0, r = k - 1;
    for(ll i = k; i < n; i++) {
        sum -= a[i - k];
        sum += a[i];
        if(sum > maxi) maxi = sum, l = i - k + 1, r = i;
    }
    // cout << l << ' ' << r << ' ' << maxi << '\n';
    vll b, c;
    for(ll i = 0; i < l; i++) {
        b.push_back(a[i]);
    }
    
    for(ll i = r + 1; i < n; i++) {
        c.push_back(a[i]);
    }
    
    sum = 0;
    ll maxi1 = inf;
    if(b.size() >= k) { 
        for(ll i = 0; i < k; i++) sum += b[i];
        ll maxi1 = sum;
        l = 0, r = k - 1;
        for(ll i = k; i < b.size(); i++) {
            sum -= b[i - k];
            sum += b[i];
            if(sum > maxi1) maxi1 = sum;
        }
    }
    sum = 0;
    ll maxi2 = inf;
    if(c.size() >= k) { 
        for(ll i = 0; i < k; i++) sum += c[i];
        maxi2 = sum;
        for(ll i = k; i < c.size(); i++) {
            sum -= c[i - k];
            sum += c[i];
            if(sum > maxi2) maxi2 = sum;
        }
    }
    cout << min(maxi1, maxi2) << '\n';
    /*for(ll & v : a) cout << v << ' ';
    cout << '\n';
    for(ll & v : b) cout << v << ' ';
    cout << '\n';
    for(ll & v : c) cout << v << ' ';
    cout << '\n';*/


}
