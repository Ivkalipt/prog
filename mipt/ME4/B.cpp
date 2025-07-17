#pragma gcc optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define ld long double
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
    ll a, b, c, n, cost = 0;
    cin >> a >> b >> c >> n;
    ll cur = min({a * 28, b * 4, c});
    if(n >= 28) {
        cost += (ll)(n / 28) * cur;
        // cout << cost << '\n';
        n %= 28;
    }
    cur = min({a * 7, b, c});
    if(cur == c) {
        cost += c;
        cout << cost << '\n';
        return 0;
    }
    if(n >= 7) {
        cost += (ll)(n / 7) * cur;
        // cout << cost << '\n';
        n %= 7;
    }
    if(n < 28) {
        cur = min({c, (ll)ceill(n / 7.0) * b, a * n});
        // cout << cur << '\n';
        cout << cur + cost << '\n';
        return 0;
    }
}
