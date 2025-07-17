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

ll inf = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for (ll & c : a) cin >> c;

    vll ans(n, -1), b = {0};

    for (int i = 1; i < n; ++i) {
        while (!b.empty() && a[i] < a[b.back()]) {
            ans[b.back()] = i;
            b.pop_back();
        }
        b.push_back(i);
    }

    for (ll & c : ans) cout << c << ' ';
    return 0;
}
