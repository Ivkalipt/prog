// #pragma gcc optimize ("o3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc push_options
// #pragma gcc pop_options
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

int main() {
    ll n, l, r;
    cin >> n;
    vpll a, b;
    for(ll i = 0; i < n; i++) {
        cin >> l >> r;
        a.push_back({l, 0});
        a.push_back({r, 1});
    }
    sort(all(a), [](pll x, pll y) {
        return (x.F < y.F || (x.F == y.F && x.S < y.S));
    });
    ll start, end;
    bool flag = 0;
    ll cnt = 0;
    for(pll c : a) {
        if(c.S) {
            cnt--;
            if(!cnt) b.push_back({start, c.F});
        }
        else {
            if(!cnt) start = c.F;
            cnt++;
        }
    }
    cout << b.size() << '\n';
    for(pll c : b) cout << c.F << ' ' << c.S << '\n';
    

    
}
