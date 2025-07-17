#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll MOD = 1e9 + 7, k = 27, maxn = 1e5 + 5;
ll h[maxn], powers[maxn], n;

void init_hash(string & s) {
    n = s.size();
    powers[0] = 1;
    for(ll i = 1; i <= n; i++) {
        powers[i] = powers[i - 1] * k % MOD;
        ll c = s[i - 1] - 'a' + 1;
        h[i] = (h[i - 1] % MOD + c * powers[i - 1] % MOD) % MOD;
    }
}

ll get_hash(ll l, ll r) {
    return (h[r] - h[l - 1] + MOD) % MOD * powers[n - l] % MOD;
}

void solve() {
    string s;
    ll m;
    cin >> s >> m;
    init_hash(s);
    while(m--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (get_hash(a, b) == get_hash(c, d) ? "Yes" : "No") << '\n';
    }
}

int main() {
    solve();
}

