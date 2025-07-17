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

ll G(ll u, ll k) {
    ll s = u;
    ll k1 = k;
    while(u / k != 0) {
        s += u / k;
        k *= k1;
    }
    return s;
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = n * k;
    while(r - l > 1) {
        ll mid = (r + l) / 2;
        if(G(mid, k) >= n) {
            r = mid;
        }
        else l = mid;
    }
    cout << r << '\n';
}
