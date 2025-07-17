// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
// #pragma GCC optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
// #define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

int main() {
    ll n, k, p, t, cnt = 0;
    bool f = 0;
    cin >> n >> k >> p;
    unordered_set<ll> carsNow;
    vll a(p), b(n, 0);
    for(ll & c : a) cin >> c, b[c]++;
    for(ll c : a) {

        if(carsNow.size() == k){
            for(ll v : carsNow)
                if(b[v] == 1) {
                    carsNow.erase(v);
                    b[v]--;
                    f = 1;
                    break;
                }
            if(!f) b[*carsNow.begin()]--, carsNow.erase(*carsNow.begin()); 
        }
        if(carsNow.size() < k) carsNow.insert(c);

    }

}
