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

vector<string> a;

void rec(ll s, ll k, vll &cur, ll n) {
    if(cur.size() == k) {
        for(ll c : cur) cout << c << ' ';
        cout << '\n';
        return;
    }
    /*if(cur.size() == 0) {
        cur.push_back(p);
        p++;
        rec(pos + 1, k, n, cur);
        return;
    }*/
    for(ll i = 1; i <= s; i++) {
        if(i >= k - cur.size()) {
            cur.push_back(i);
            rec(i - 1, k, cur, n);
            cur.pop_back();
        }
    }
}

int main() {
    ll n, k;
    cin >> n >> k;
    vll cur;
    for(ll i = k; i <= n; i++) {
        cur.push_back(i);
        rec(i - 1, k, cur, n);
        cur.pop_back();
    }
}
