#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using ld = long double;
using vll = vector<long long>;

const ll MOD = 1e9 + 7, k = 31;

ll h[100010], p[100010], sc[100010];

void hashf(string & s) {
    ll n = s.size();
    p[0] = 1;
    h[0] = 0;
    for(ll i = 0; i < n; i++) {
        sc[i] = s[i] - 'a' + 1;
    }
    for(ll i = 1; i <= n; i++) {
        p[i] = (p[i - 1] * k) % MOD;
        h[i] = (h[i - 1] + p[i - 1] * sc[i - 1]) % MOD;
    }
}

ll hash_substring(ll l, ll r, ll n) {
    return ((h[r] - h[l - 1]) * p[n - l + 1]) % MOD;
}

int main() {
    string s;
    cin >> s;
    hashf(s);
    ll q, n = s.size();
    // for(ll i = 0; i <= n; i++) cout << h[i] << ' ';
    // cout << '\n';
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        ll lx = 0, rx = min(n - l + 1, n - r + 1);
        while(lx < rx) {
            ll m = (lx + rx + 1) / 2;
            if(hash_substring(l, l + m - 1, n) == hash_substring(r, r + m - 1, n)) {
                lx = m;
            }
            else {
                rx = m - 1;
            }
        }
        cout << lx << '\n';
    }

    return 0;
}
