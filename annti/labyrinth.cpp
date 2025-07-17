// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll int
#define v(a) vector<a>
#define vv(a) vector<vector<a>>
#define F first
#define S second

using namespace std;

vv(bool) used(1000, vector<bool>(1000));
vv(string) way(1000, v(string)(1000, ""));
ll n, m;

void dfs(pair<ll, ll> v, vector<string> &plan) {
    // cout << v.F << ' ' << v.S << endl;
    ll i = v.F; ll j = v.S;
    used[i][j] = 1;
    if(j > 0 && !used[i][j-1] && (plan[i][j-1] == '.' || plan[i][j-1] == 'B')) {
        way[i][j-1] = way[i][j] + 'L';
        dfs({i, j-1}, plan);
    }
    if(j < m - 1 && !used[i][j+1] && (plan[i][j+1] == '.' || plan[i][j+1] == 'B')) {
        way[i][j+1] = way[i][j] + 'R';
        dfs({i, j+1}, plan);
    }
    if(i > 0 && !used[i-1][j] && (plan[i-1][j] == '.' || plan[i-1][j] == 'B')) {
        way[i-1][j] = way[i][j] + 'U';
        dfs({i-1, j}, plan);
    }
    if(i < n - 1 && !used[i+1][j] && (plan[i+1][j] == '.' || plan[i+1][j] == 'B')) {
        way[i+1][j] = way[i][j] + 'D';
        dfs({i+1, j}, plan);
    }
}

int main() {
    ll k = 0;
    cin >> n >> m;
    vector<string> plan(n);
    for(ll i = 0; i < n; i++) {
        cin >> plan[i];
        plan[i] = plan[i];
    }
    // cout << 0 << endl;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(plan[i][j] == 'A') {
                dfs({i, j}, plan);
            }
        }
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(plan[i][j] == 'B') {
                if(way[i][j] == "") {
                    cout << "NO";
                }
                else {
                    cout << "YES" << "\n" << way[i][j].size() << "\n" << way[i][j];
                }
            }
        }
    }

    /*for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if(plan[i][j] == '.' && !used[i][j]) {
                // cout << i << ' ' << j << endl;
                k++;
                dfs({i, j}, plan);
            }
        }
    }*/
    

}