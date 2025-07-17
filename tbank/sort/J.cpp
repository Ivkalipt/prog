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

const ll inf = 1e9 + 7;

int main() {
    ll n, m;
    cin >> n >> m;
    vll a(n * m);
    ll l = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> a[l];
            l++;
        }
    }
    ll k;
    cin >> k;
    vll withOutPilot(k);
    for(ll & c : withOutPilot) cin >> c;
    sort(all(a)), sort(all(withOutPilot));
    ll i = 0, j = 0;
    ll ans = 0;
    while(i != n * m && j != k) {
        if(a[i] >= withOutPilot[j]) {
            ans++;
            i++, j++;
        }
        else {
            i++;
        }
    }
    cout << ans << '\n';

    
    
}
