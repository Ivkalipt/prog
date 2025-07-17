#pragma GCC optimize("O3,unroll-loops")
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

const ll maxn = 101, inf = 1e18;

ll a[maxn][maxn], s[maxn][maxn];

int main() {
    string s;
    cin >> s;
    map<char, ll> cnt;
    for(char c : s) cnt[c]++;
    string a = "";
    char sym = '/';
    bool f = 0;
    for(auto [c, n] : cnt) {
        if(n & 1) {
            if(sym != '/') {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
            else {
                sym = c;
            }
        }
        n /= 2;
        for(ll i = 0; i < n; i++) {
            a += c;
        }
    }
    string ans = a;
    if(sym != '/') a += sym;
    reverse(all(a));
    ans += a;
    cout << ans << '\n';
}
