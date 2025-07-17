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
    ll l = 0, r = 0, maxL = 0, maxR = 0, maxVal = a[0], sum = 0, pos = -1;
    for(ll i = 0; i < n; i++) {
        sum += a[i];
        if(sum > maxVal) {
            maxVal = sum;
            maxR = i;
            maxL = pos + 1;
        }
        
        if(sum < 0) {
            sum = 0;
            pos = i;
        }


    }
    cout << maxL + 1 << ' ' << maxR + 1 << ' ' << maxVal << '\n';
}
