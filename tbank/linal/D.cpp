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
    ll n, m, t, maxi = 0;
    cin >> n >> m;
    vll scan(m + 1, 0);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> t;
            if(t == 0) scan[j]++;
            if(t == 1) scan[j] = 0;
        }
        stack<pll> curh;
        curh.push({0, -1});
        ll Ss = 0, k;
        for(ll j = 0; j <= m; j++) {
            k = j + 1;
            while(curh.top().S >= scan[j]) {
                k = curh.top().F; 
                ll h = curh.top().S;
                curh.pop();
                if(Ss < h * (j - k + 1)) Ss = h * (j - k + 1);
            }
            curh.push({k, scan[j]});
        }
        if(Ss > maxi) maxi = Ss;
    }
    cout << maxi << '\n';
}
