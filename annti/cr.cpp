// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options


#include <bits/stdc++.h>

#define ll int
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define F first
#define S second

using namespace std;

vector<vector<bool>> used(1000, vector<bool>(1000));
ll n, m;

void dfs(pair<ll, ll> v, vector<string> &plan) {
    // cout << v.F << ' ' << v.S << endl;
    ll i = v.F; ll j = v.S;
    used[v.F][v.S] = 1;
    if(j > 0 && !used[i][j-1] && plan[i][j-1] == '.') {
        dfs({i, j-1}, plan);
    }
    if(j < m - 1 && !used[i][j+1] && plan[i][j+1] == '.') {
        dfs({i, j+1}, plan);
    }
    if(i > 0 && !used[i-1][j] && plan[i-1][j] == '.') {
        dfs({i-1, j}, plan);
    }
    if(i < n - 1 && !used[i+1][j] && plan[i+1][j] == '.') {
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
            if(plan[i][j] == '.' && !used[i][j]) {
                // cout << i << ' ' << j << endl;
                k++;
                dfs({i, j}, plan);
            }
        }
    }
    
    cout << k << "\n";

}