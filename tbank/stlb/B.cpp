#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

const ll inf = 1e9 + 7, MAXN = 31;

int main() {
    ll m;
    cin >> m;
    vpll a(MAXN);
    for(ll i = 0; i < MAXN; i++) {
        cin >> a[i].F;
        a[i].S = (1LL << i);
    }
    for(ll i = 1; i < MAXN; i++) {
        if(a[i - 1].F * 2 > a[i].F)
            a[i].F = a[i - 1].F * 2;
    }
    sort(all(a), [](pll x, pll y){
            return x.F > y.F || (x.F == y.F && x.S < y.S);
            });
    ll cost = 0;
    for(ll i = 0; i < MAXN; i++) {
        // cout << m / a[i].F * a[i].S << '\n';
        cost += m / a[i].F * a[i].S;
        m %= a[i].F;
    }
    cout << cost << '\n';
    /*for(ll i = 0; i < MAXN; i++) {
        cout << a[i] << ' ';
    }*/
    
}
