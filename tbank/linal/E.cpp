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
    ll n, k;
    cin >> n >> k;
    vll a(n), pref(n, 0);
    vector<bool> b(n, 0);
    ll mini = inf;
    for(ll & c : a) cin >> c;
    for(ll i = 0; i < n; i++) {
        if(a[i] > a[i - 1]) b[i] = 1;
        pref[i] = b[i] + (i > 0 ? pref[i - 1] : 0);
    }
    k--;
    for(ll i = k; i < n; i++) {
        ll dist = pref[i] - pref[i - k];
        if(mini > dist) mini = dist;
        // cout << dist << ' ';
    }
    /*cout << '\n';
    for(ll c : a) cout << c << ' ';
    cout << '\n';
    for(ll c : pref) cout << c << ' ';
    cout << '\n';
    for(ll c : b) cout << c << ' ';*/
    cout << '\n' << mini << '\n';
    
}
