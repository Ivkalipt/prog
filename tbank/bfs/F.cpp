#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("Ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

using namespace std;

ll up(ll x) {
    return x + 1000;
}

ll down(ll x) {
    return x - 1;
}

ll moveR(ll x) {
    return x / 10 + (x % 10) * 1000;
}

ll moveL(ll x) {
    return (x % 1000) * 10 + x / 1000;
}

vll d(1e4, -1), p(1e4, -1);

void bfs(ll s, ll t) {
    d[s] = 0;
    queue<ll> q;
    q.push(s);
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        vll g = {moveR(v), moveL(v)};
        if (v < 9000) g.push_back(up(v));
        if (v % 10 != 0) g.push_back(down(v));
        for (ll u : g)
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                p[u] = v;
                q.push(u);
                if (u == t) return;
            }
    }
}

int main() {
    ll s, t;
    cin >> s >> t;
    bfs(s, t);
    vll ans;
    ll ind = t;
    ans.push_back(t);
    while (p[ind] != -1) {
        ans.push_back(p[ind]);
        ind = p[ind];
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (ll c : ans) cout << c << '\n';
}
