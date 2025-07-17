#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 9;
const ll k = 1e6 + 3;
const int maxn = 1e6 + 5;

ll straight_h[maxn], reverse_h[maxn], power[maxn];

void init_hash(const vector<ll>& s) {
    int n = s.size();
    power[0] = 1;
    for (int i = 0; i < n; ++i) {
        power[i + 1] = (power[i] * k) % MOD;
        straight_h[i + 1] = (straight_h[i] * k + s[i]) % MOD;
    }
    for (int i = n - 1; i >= 0; --i) {
        reverse_h[i] = (reverse_h[i + 1] * k + s[i]) % MOD;
    }
}

ll get_straight_hash(int l, int r) {
    return (straight_h[r + 1] - straight_h[l] * power[r - l + 1] % MOD + MOD) % MOD;
}

ll get_reverse_hash(int l, int r) {
    return (reverse_h[l] - reverse_h[r + 1] * power[r - l + 1] % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    init_hash(a);

    vector<int> ans;
    for (int K = 1; K <= n; ++K) {
        int mirror = n - K;
        if (mirror < 0) continue;
        bool ok = true;
        if (mirror > 0) {
            ll straight = get_straight_hash(0, mirror - 1);
            ll reversed = get_reverse_hash(K, K + mirror - 1);
            if (straight != reversed) {
                ok = false;
            }
        }
        if (ok) {
            ans.push_back(K);
        }
    }

    sort(ans.begin(), ans.end());
    for (int K : ans) {
        cout << K << ' ';
    }
    cout << '\n';

    return 0;
}
