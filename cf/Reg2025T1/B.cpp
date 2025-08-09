#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 4e18;
constexpr ll N = 2e5;

char p = {'2', '3', '5', '7'};

ll ch(char & t) {
    ll cnt = 0;
    for (char x : p) if (t >= x) cnt++;
    return cnt;
}

int main() {
    string l, r;
    cin >> l >> r;
    ll n = sz(l), m = sz(r);
    vector dp(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        if (l[i] == '1') continue;
        
    }



}