// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options
#pragma GCC optimize ("Ofast")

// #define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define v(a) vector<a>
// #define vv(a) vector<vector<a>>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define F first
#define S second
#define all(a) a.begin(), a.end()

using namespace std;

bool used[11];

void rec(ll pos, ll n, vll &cur) {
    if(pos == n) {
        for(ll c : cur) cout << c;
        cout << '\n';
        return;
    }
    for(ll i = 1; i <= n; i++) {
        if(!used[i]) {
            cur[pos] = i;
            used[i] = true;
            rec(pos + 1, n, cur);
            used[i] = false;
        }
    }
}

int main() {
    ll n;
    cin >> n;
    vll cur(n);
    rec(0, n, cur);
}
