#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>

using namespace std;

///bool used[51];
bool flag = 0;
short used2[50];

void dfs(ll v, vvll &g) {
    used2[v] = 1;
    for(auto u:g[v]) {
        if(!used2[u]) {
            dfs(u, g);
            used2[u] = 2;
        }
        else if(used2[u] == 1) {
            flag = 1;
        }
    }
}

/*void dfs(ll v, vvll g) {
    used[v] = true;
    for(auto u:g[v]) {
        if(!used[u]) {
            used2[u] = 1;
            dfs(u, g);
            used2[u] = 2;
        }
        else if (used[u] && used2[u] == 1) {
            flag = 1;
        }
        else
        {
            flag = 1;
        }
    } 


}*/

int main() {
    ll n;
    bool t;
    cin >> n;
    vvll g(n);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> t;
            if (t) {
                g[i].push_back(j);
            }
        }
    }
    for(ll i = 0; i < n; i++) {
        if(!used2[i]) {
            dfs(i, g);
        }
    }
    
    cout << flag;
}