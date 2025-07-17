#pragma GCC optimize("O3,unroll-loops")
// #pragma gcc target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma gcc optimize ("ofast")

#include <bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vvll vector<vector<ll>>
#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end() 

using namespace std;

ll inf = 1e16;

vector<vector<bool>> used;
ll n, m;

void dfs(ll i, ll j, vector<string> & g) {
    used[i][j] = true;
    if(i + 1 < n && g[i + 1][j] != '.' && !used[i + 1][j]) dfs(i + 1, j, g);
    if(i - 1 > -1  && g[i - 1][j] != '.' && !used[i - 1][j]) dfs(i - 1, j, g);
    if(j + 1 < m && g[i][j + 1] != '.' && !used[i][j + 1]) dfs(i, j + 1, g);
    if(j - 1 > -1 && g[i][j - 1] != '.' && !used[i][j - 1]) dfs(i, j - 1, g);
}

int main() {
    ll cnt = 0;
    cin >> n >> m;
    vector<string> g(n);
    used.resize(n, vector<bool>(m, 0));
    for(string & c : g) cin >> c;

    // dfs(0, 3, g);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(g[i][j] == '#' && !used[i][j]) {
                dfs(i, j, g);
                cnt++;
    /*for(vector<bool> c : used) {
        for(bool v : c) {
            cout << v;
        }
        cout << '\n';
    }*/
            }
        }
    }

    cout << cnt << '\n';

}
