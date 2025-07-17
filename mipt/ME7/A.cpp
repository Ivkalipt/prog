#pragma gcc optimize ("o3,unroll-loops")
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
    fastio;
    ll a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    if(a + b + c != x + y + z) cout << -1 << '\n', exit(0);
    ll a1 = abs(a - x), b1 = abs(b - y), c1 = abs(c - z);
    cout << (a1 + b1 + c1) / 2 << '\n';
    
}
