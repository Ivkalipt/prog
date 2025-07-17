#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second
#define all(a) a.begin(), a.end()

void rec(ll n, vll & cur) {
    if(n == 0) {
        for(ll i = 0; i < cur.size(); i++) cout << cur[i] << (i == cur.size() - 1 ? "" : "+");
        cout << '\n';
        return;
    }
    for(ll i = cur.back(); i <= n; i++) {
        cur.push_back(i);
        rec(n - i, cur);
        cur.pop_back();
    }
}

int main() {
    ll n;
    cin >> n;
    vll cur;
    for(ll i = 1; i < n; i++) {
        cur.push_back(i);
        rec(n - i, cur);
        cur.pop_back();
    }
    
}
