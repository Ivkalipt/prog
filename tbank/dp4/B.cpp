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
vector<vll> dp(1 << maxn, vll(maxn, inf)), pr(1 << maxn, vll(maxn, -1));

int main() {
    for(ll i = 0; i < maxn; i++) dp[1 << i][i] = 0;
    ll n, t;
    cin >> n;
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < n; j++)
            cin >> t, adj[i][j] = (t == 0 ? inf : t);
    for(ll mask = 0; mask < (1 << n); mask++) {
        for(ll p = 0; p < n; p++) {
            if((1 << p) & mask)
            for(ll last = 0; last < n; last++) {
                if(p != last && (1 << last) & mask) {
                    if(dp[mask][p] > dp[mask ^ (1 << p)][last] + adj[p][last]) {
                        dp[mask][p] = dp[mask ^ (1 << p)][last] + adj[p][last];
                        pr[mask][p] = last;
                    }
                }
            }
        }
    }

    /*for(ll mask = 0; mask < (1 << n); mask++) {
        for(ll last = 0; last < n; last++) {
            if((mask >> last) & 1) {
                for(ll p = 0; p < n; p++) {
                    if((mask >> p) & 1 && dp[mask ^ (1 << p)][p] + adj[p][last] < dp[mask][last]) {
                        dp[mask][last] = dp[mask ^ (1 << p)][p] + adj[p][last];
                        pr[last] = p;
                    }
                }
            }
        }   
    }*/
    ll mn = inf, last = 0;
    
    for(ll i = 1; i < n; i++) {
        if(dp[(1 << n) - 1][i] < mn) mn = dp[(1 << n) - 1][i], last = i;
    } 
    if(mn == inf) {
        cout << -1 << '\n';
    }
    else {
        vll ans;
        cout << mn << '\n';
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
}
