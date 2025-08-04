#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define F first
#define S second
#define pb push_back

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

const int MAXN = 2e5 + 1;

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n == 1 || m == 1 || (n == 2 && m == 2)) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) solve();
}