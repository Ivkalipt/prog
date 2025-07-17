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

ll cnt = 0;

vll merge(vll a, vll b) {
    ll i = 0, j = 0, n = a.size(), m = b.size();
    vll res;
    while(i != n && j != m) {
        if(a[i] >= b[j]) res.push_back(b[j++]), cnt += n - i;
        else res.push_back(a[i++]);
    }
    while(i != n) {
        res.push_back(a[i++]);
    }
    while(j != m) {
        res.push_back(b[j++]);
    }
    return res;
}

vll merge_sort(vll a) {
    if(a.size() < 2) return a;
    ll m = a.size() >> 1;
    return merge(
            merge_sort(vll(a.begin(), a.begin() + m)),
            merge_sort(vll(a.begin() + m, a.end()))
           );
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll & c : a) cin >> c;
    merge_sort(a);
    cout << cnt << '\n';
    cnt = 0;
}

int main() {
    ll t;
    cin >> t;
    while(t--) solve();
}
