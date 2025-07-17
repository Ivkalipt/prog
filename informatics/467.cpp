#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ll n, m, x, y;
    cin >> n >> m;
    vector<vector<ll>> AdjMat(n, vector<ll>(n, 0));
    for(ll i = 0; i < m; i++) {
        cin >> x >> y;
        AdjMat[x-1][y-1] = 1;
    }
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cout << AdjMat[i][j] << " ";
        }
        cout << "\n";
    }
    
}