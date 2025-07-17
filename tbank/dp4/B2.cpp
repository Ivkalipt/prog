#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0);
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<long long>;

const ll maxn = 18, inf = 1e18;

ll adj[maxn][maxn];
//vector<vll> dp(1 << maxn, vll(maxn, inf)), pr(1 << maxn, vll(maxn, -1));

int main() {
    fastio;
    ll n;
    cin >> n;
    vector<vll> dp(1 << n, vll(n, inf)), pr(1 << n, vll(n, -1));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> adj[i][j];
            if(adj[i][j] == 0 && i != j) adj[i][j] = inf;
        }
    }
    
    dp[1][0] = 0;
    
    for(ll mask = 0; mask < (1 << n); mask++) {
        for(ll last = 0; last < n; last++) {
            if(!(mask & (1 << last))) continue;
            for(ll p = 0; p < n; p++) {
                if(mask & (1 << p)) continue; 
                if(dp[mask ^ (1 << p)][p] > dp[mask][last] + adj[last][p]) {
                    dp[mask ^ (1 << p)][p] = dp[mask][last] + adj[last][p];
                    pr[mask ^ (1 << p)][p] = last;
                }
            }
        }
    }
    
    
    ll mn = inf, last = 0;
    for(ll i = 0; i < n; i++) {
        if(dp[(1 << n) - 1][i] < mn) mn = dp[(1 << n) - 1][i], last = i;
    } 
    if(mn == inf) {
        cout << -1 << endl;
    }
    else {
        vll ans;
        cout << mn << endl;
        ll mask = (1 << n) - 1, ind = last;
        while(mask != 0) {
            ans.push_back(ind);
            mask = (~(1 << ind)) & mask;
            ind = pr[mask][ind];
            /*for(ll c : pr[mask]) cout << c << ' ';
            cout << '\n';*/
        }
        for(ll c : ans) cout << c << ' ';
        cout << '\n';
    }

    return 0;
}
