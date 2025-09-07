#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define F first
#define S second

using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vll pa(n + 1), pc(n + 1), indexes;
    for (ll i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + (s[i - 1] == 'a' ? 1 : 0);
        pc[i] = pc[i - 1] + (s[i - 1] == 'c' ? 1 : 0);
        s[i - 1] == 'b' ? indexes.push_back(i) : (void)0;
    }

}