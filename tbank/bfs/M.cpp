#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);

using namespace std;
using ll = long long;
using vll = vector<long long>;
using pll = pair<ll, ll>;

#define F first
#define S second

const ll inf = 1e18;

vll dist, p, num;

void bfs(ll s, ll k, vll & d) {
    dist[s] = 0;
    queue<ll> q;
    q.push(s);
    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        for(ll c : d) {
            ll u = (v * 10 + c) % k;
            if(dist[v] + 1 < dist[u]) {
                dist[u] = dist[v] + 1;
                q.push(u);
                p[u] = v;
                num[u] = c;
            }
            // cout << 1;
            // cout << v * 10 + c << ' ' << dist[(v * 10 + c) % k] << "| ";
        }
        // cout << '\n';
    }
}

int main() {
    string a1;
    ll k, n;
    cin >> a1 >> k >> n;
    dist.resize(k, inf);
    p.resize(k, -1);
    num.resize(k, -1);
    vll d(n);
    for(ll & c : d) cin >> c;
    sort(d.begin(), d.end());
    ll a = 0;
    for(char to : a1) {
        a = (to - '0') + a * 10;
        a %= k;
    }
    if(a % k == 0) cout << a1 << '\n', exit(0);
    bfs(a, k, d);
    // cout << dist[0] << '\n';
    if(dist[0] == inf) cout << -1 << '\n', exit(0);
    ll ind = 0;
    string ans = "";
    while(p[ind] != -1) {
        ans += num[ind] + '0';
        ind = p[ind];
    }

    // for(ll c : p) cout << c << ' ';
    reverse(ans.begin(), ans.end());
    cout << a1 + ans << '\n';
    // cout << (char)(-1 + '0');
}
