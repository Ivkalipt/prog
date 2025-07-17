#pragma GCC optimize("Ofast")
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

const ll maxn = 1e5;

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll sum = a + b + c, mx = max({a, b, c});
    if(2 * mx <= sum + n) cout << sum;
    else cout << 2 * (sum - mx) + n;
    cout << '\n';
}
