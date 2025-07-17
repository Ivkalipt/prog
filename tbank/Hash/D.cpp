#pragma GCC optimize ("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7, BASE = 29, MAXN = 1e6 + 5;
ll h[MAXN], power[MAXN];

void init_hash(string & s) {
    power[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        power[i + 1] = (power[i] * BASE) % MOD;
        ll c = s[i] - 'a' + 1;
        h[i + 1] = (h[i] * BASE + c) % MOD;
    }
}

ll get_hash(int l, int r) {
    return (h[r] - h[l] * power[r - l] % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    init_hash(s);
    int n = s.size();

    for (int k = n; k >= 1; k--) {
        if (n % k != 0) continue;
        int t_len = n / k;
        ll t_hash = get_hash(0, t_len);
        bool ok = true;
        for (int i = 1; i < k; i++) {
            ll curr_hash = get_hash(i * t_len, (i + 1) * t_len);
            if (curr_hash != t_hash) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << k << '\n';
            return 0;
        }
    }

    cout << 1 << '\n';
    return 0;
}
