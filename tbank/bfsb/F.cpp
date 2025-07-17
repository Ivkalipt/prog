#pragma GCC optimize ("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

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

void bfs(ll x1, ll y1, ll n, vvll & d) {
    d[x1][y1] = 0;
    queue<pll> q;
    q.push({x1, y1});
    while(!q.empty()) {
        ll x = q.front().F, y = q.front().S;
        q.pop();
        vpll a;
        if(x + 2 < n && y + 1 < n) a.push_back({x + 2, y + 1});
        if(x + 2 < n && y - 1 >= 0) a.push_back({x + 2, y - 1});
        if(x - 2 >= 0 && y + 1 < n) a.push_back({x - 2, y + 1});
        if(x - 2 >= 0 && y - 1 >= 0) a.push_back({x - 2, y - 1});
        if(y + 2 < n && x + 1 < n) a.push_back({x + 1, y + 2});
        if(y + 2 < n && x - 1 >= 0) a.push_back({x - 1, y + 2});
        if(y - 2 >= 0 && x + 1 < n) a.push_back({x + 1, y - 2});
        if(y - 2 >= 0 && x - 1 >= 0) a.push_back({x - 1, y - 2});
        for(pll u : a) {
            if(d[u.F][u.S] == -1) {
                d[u.F][u.S] = d[x][y] + 1;
                q.push({u.F, u.S});
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    vvll d1(n, vll(n, -1)), d2(n, vll(n, -1));
    bfs(x1, y1, n, d1), bfs(x2, y2, n, d2);
    ll mini = inf;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(d1[i][j] == d2[i][j] && d1[i][j] < mini && d1[i][j] != -1) mini = d1[i][j]; 
        }
    }
    cout << (mini == inf ? -1 : mini) << '\n';
}
