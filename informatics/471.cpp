#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    
    ll n, m, t1, t2;
    cin >> n >> m;
    vector<pair<ll, ll>> edges(m);
    vector<vector<ll>> v(n, vector<ll>(0));
    for(ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        edges[i] = {t1, t2};
    }
    for(auto [a, b] : edges) {
        v[a-1].push_back(b);
        v[b-1].push_back(a);
    }
    for(ll i = 0; i < n; i++) {
        cout << v[i].size() << "\n";
    }
}