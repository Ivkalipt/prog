// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

vv(bool) used(100, v(bool)(100, 0));
ll n, m;
char flag = 'N';

void bfs(pair<ll, ll> v, v(string) &g) {
    queue<ll> q;
}

int main() {
    fastio;
    ll xs, ys, xe, ye, k = 0;
    string t;
    cin >> n;
    v(string) g;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        g.push_back(t);
    }
    
    

    cout << flag;
    cout << "\n";
    return 0;
}

/*
ll i = v.F; ll j = v.S;
    used[v.F][v.S] = 1;
    
    if(j > 0 && !used[i][j-1] && (g[i][j-1] == '.' || g[i][j-1] == 'X')) {
        if(g[i][j-1] == 'X') {
            flag = 'Y';
        }
        dfs({i, j-1}, g);
    }
    if(j < m - 1 && !used[i][j+1] && (g[i][j+1] == '.' || g[i][j+1] == 'X')) {
        if(g[i][j+1] == 'X') {
            flag = 'Y';
        }
        dfs({i, j+1}, g);
    }
    if(i > 0 && !used[i-1][j] && (g[i-1][j] == '.' || g[i-1][j] == 'X')) {
        if(g[i-1][j] == 'X') {
            flag = 'Y';
        }
        dfs({i-1, j}, g);
    }
    if(i < n - 1 && !used[i+1][j] && (g[i+1][j] == '.' || g[i+1][j] == 'X')) {
        if(g[i+1][j] == 'X') {
            flag = 'Y';
        }
        dfs({i+1, j}, g);
    }
*/