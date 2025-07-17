// #pragma GCC optimize ("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC push_options
// #pragma GCC pop_options

#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>
#define v(a) vector<a>
//#define vv(a) vector<vector<a>>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define F first
#define S second

using namespace std;

bool used[100];
string flag = "NO";

struct xyr
{
    ll x, y, r;
};

void dfs(ll v, ll vx, vvll g) {
    used[v] = 1;
    for(auto u:g[v]) {
        if(u == vx) {
            cout << "YES";
            exit(0);
        }
        if(!used[u]) {
            dfs(u, vx, g);
        }
    }
}

int main() {
    fastio;
    ll n, d, tx, ty, tr;
    cin >> n >> d;
    vvll g(n);
    v(xyr) XYR(n);
    for(ll i = 0; i < n; i++) {
        cin >> tx >> ty >> tr;
        XYR[i] = {tx, ty, tr};
    }
    for(ll i = 0; i < n-1; i++) {
        for(ll j = i+1; j < n; j++) {
            if(sqrt( (XYR[i].x-XYR[j].x)*(XYR[i].x-XYR[j].x) + (XYR[i].y-XYR[j].y)*(XYR[i].y-XYR[j].y))-XYR[i].r-XYR[j].r <= d) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    dfs(0, n-1, g);
    cout << "NO";
    return 0;
}