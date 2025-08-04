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

void solve() {
    string s;
    cin >> s;
    vector<char> str(all(s));
    ll n = str.size();
    for (ll i = 0; i < n; i++) {
        if (str[i] == 'F' || str[i] == 'N') {
            str.push_back(str[i]);
            str[i] = '0';
        }
    }
    for (char c : str) if (c != '0') cout << c;
    cout << '\n';
}

int main() {
    ll t; cin >> t; while (t--) solve();
}