#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<long long>;

const ll maxn = 510, maxq = 3010;

ld dp[maxn][maxq];

void solve() {
    ll n;
    cin >> n;
    ll s, i, m;
    s = 0, i = 1, m = 0;
    while(i <= n) {
        ll x;
        cin >> x;
        s += x;
        if(s > 0) {
            if(m <= s) {
                m = s;
            }
        }
        else {
            s = 0;
        }
        i++;
    }
    cout << m << '\n';
}

int main() {
    solve();
} 
