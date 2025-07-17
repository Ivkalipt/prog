#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;

const ll inf = 1e18;

int main() {
    string s;
    cin >> s;
    ll q;
    cin >> q;
    for (ll k = 0; k < q; ++k) {
        ll i, j;
        cin >> i >> j;
        ll cnt = 0;
        while (s[i + cnt - 1] == s[j + cnt - 1]) {            
            cnt++;
            if (i + cnt > s.size() || j + cnt > s.size()) break;
        }
        cout << cnt << '\n';
    }

    return 0;
}
