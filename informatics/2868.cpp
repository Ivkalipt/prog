#include <iostream>
#include <vector>
#define ll long long

using namespace std;


bool used[100000], flag = 0;



void dfs(ll v, vector<vector<ll>> &g) {
    used[v] = true;
    ll k = 0;
    for(auto u:g[v-1]) {
        if(!used[u]) {
            dfs(u, g);
            
        }
        else
        {
            k++;
        }
    }
    if(k > 1) {
        flag = 1;
    }
}

int main() {
    ll n, m, t1, t2, k = 0;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for(ll i = 0; i < m; i++) {
        cin >> t1 >> t2;

        g[t1-1].push_back(t2);
        g[t2-1].push_back(t1);
    }
    
    
    for(ll i = 1; i <= n; i++) {
        if(!used[i]) {
            dfs(i, g);
            k++;
            
        }
        
        
        
    }
    if(k > 1) {
        flag = 1;
    }
    
    if(flag){
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return 0;
}