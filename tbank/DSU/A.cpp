#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vll = vector<long long>;

const ll inf = 1e16, maxn = 2e5;

ll parent[maxn], rang[maxn];


int p[maxn], s[maxn];

ll leader(int v) {
    return (p[v] == v) ? v : p[v] = leader(p[v]);
}

void unite(ll a, ll b) {
    a = leader(a), b = leader(b);
    if (s[a] > s[b])
        swap(a, b);
    s[b] += s[a];
    p[a] = b;
}

void init(ll n) {
    for (ll i = 0; i < n; i++)
        p[i] = i, s[i] = 1;
}


int main() {
    ll n, q;
    cin >> n >> q;
    init(n);
    while(q--) {
        ll t, v, u;
        cin >> t >> v >> u;
        v--, u--;
        if(t == 1) unite(v, u);
        else {
            cout << (leader(v) == leader(u) ? "YES" : "NO") << '\n';
        }
    }
}

