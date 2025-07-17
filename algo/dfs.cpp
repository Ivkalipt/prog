#include <iostream>
#include <vector>
#define ll long long

using namespace std;

vector<bool> used;

vector<vector<ll>> g;

void dfs(ll v, vvll g) {
    used[v] = true;
    for(auto u:g[v]) {
        if(!used[u]) {
            dfs(u, g);
        }
    }
}

int main() {
    
}