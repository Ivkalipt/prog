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
#define venom vector
#define mkpair make_pair

const ll inf = 99;

venom<vll> d;

map<pll, pll> p;

bool isOk(ll i, ll j, venom<string> & g) {
    return g[i][j] != 'X';
}

void bfs(ll si, ll sj, venom<string> & g) {
    venom<pll> a;
    if(isOk(si + 1, sj, g)) a.push_back({si + 1, sj});
    if(isOk(si, sj + 1, g)) a.push_back({si, sj + 1});
    if(isOk(si - 1, sj, g)) a.push_back({si - 1, sj});
    if(isOk(si, sj - 1, g)) a.push_back({si, sj - 1});
    queue<pll> q;
    d[si][sj] = 0;
    for(pll c : a) q.push(c), p[c] = {si, sj}, d[c.F][c.S] = 1;
    while(!q.empty()) {
        pll v = q.front();
        ll i = v.F, j = v.S;
        q.pop();
        if(p[{i, j}] == mkpair(i + 1, j)) {
            if(d[i][j + 1] > d[i][j] + 1 && isOk(i, j + 1, g))
                d[i][j + 1] = d[i][j] + 1, q.push({i, j + 1}), p[{i, j + 1}] = {i, j};
            if(d[i - 1][j] > d[i][j] + 1 && isOk(i - 1, j, g))
                d[i - 1][j] = d[i][j] + 1, q.push({i - 1, j}), p[{i - 1, j}] = {i, j}; 
        }
        if(p[{i, j}] == mkpair(i - 1, j)) {
            if(d[i][j - 1] > d[i][j] + 1 && isOk(i, j - 1, g))
                d[i][j - 1] = d[i][j] + 1, q.push({i, j - 1}), p[{i, j - 1}] = {i, j};
            if(d[i + 1][j] > d[i][j] + 1 && isOk(i + 1, j, g))
                d[i + 1][j] = d[i][j] + 1, q.push({i + 1, j}), p[{i + 1, j}] = {i, j}; 
        }
        if(p[{i, j}] == mkpair(i, j + 1)) {
            if(d[i][j - 1] > d[i][j] + 1 && isOk(i, j - 1, g))
                d[i][j - 1] = d[i][j] + 1, q.push({i, j - 1}), p[{i, j - 1}] = {i, j};
            if(d[i - 1][j] > d[i][j] + 1 && isOk(i - 1, j, g))
                d[i - 1][j] = d[i][j] + 1, q.push({i - 1, j}), p[{i - 1, j}] = {i, j}; 
        }
        if(p[{i, j}] == mkpair(i, j - 1)) {
            if(d[i][j + 1] > d[i][j] + 1 && isOk(i, j + 1, g))
                d[i][j + 1] = d[i][j] + 1, q.push({i, j + 1}), p[{i, j + 1}] = {i, j};
            if(d[i + 1][j] > d[i][j] + 1 && isOk(i + 1, j, g))
                d[i + 1][j] = d[i][j] + 1, q.push({i + 1, j}), p[{i + 1, j}] = {i, j}; 
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    venom<string> g(n);
    for(string & c : g) cin >> c;
    d.resize(n, vll(m, inf));
    ll si, sj, fi, fj;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++) {
            if(g[i][j] == 'S') si = i, sj = j;
            if(g[i][j] == 'F') fi = i, fj = j;
        }
    bfs(si, sj, g);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

