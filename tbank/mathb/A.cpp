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

using namespace std;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll m = a * d + c * b;
    ll n = b * d;
    cout << m / gcd (m, n) << ' ' << n / gcd(m, n) << '\n';
}
