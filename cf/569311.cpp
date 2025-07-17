#pragma gcc optimize ("O3,unroll-loops")
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

using namespace std;

ll maxd = 0;

string toLower(string & s) {
    string p = "";
    for(char c : s) {
        if('A' <= c && c <= 'Z') p += c + 32;
        else p += c;
    }
    return p;
}

void dfs(ll v, vvll & g, ll d) {
    if(d > maxd) maxd = d;
    for(ll u : g[v]) {
        dfs(u, g, d + 1);
    }
} 

int main() {
    ll n;
    string t1, t2;
    ll l = 0;
    cin >> n;
    vvll g(400);
    map<string, ll> a;
    for(ll i = 0; i < n; i++) {
        cin >> t1 >> t2 >> t2;
        t1 = toLower(t1), t2 = toLower(t2);
        // cout << t2 << ' ' << t1 << '\n';
        if(!a.count(t2)) {
            a[t2] = l;
            l++;
        }
        if(!a.count(t1)) {
            a[t1] = l;
            l++;
        }
        g[a[t2]].push_back(a[t1]);
    }
    /*for(vll c : g) {
        for(ll v : c) {
            cout << v << ' ';
        }
        cout << '\n';
    }*/
    dfs(a["Polycarp"], g, 0);
    cout << maxd + 1 << '\n';
    
}
