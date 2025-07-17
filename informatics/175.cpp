#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ll n, m, t;
    cin >> n >> m;
    vector<ll> cnt(n, 0);
    for(ll i = 0; i < m*2; i++) {
        cin >> t;
        cnt[t-1]++;
    }
    for(ll i = 0; i < n; i++) {
        cout << cnt[i] << " ";
    }

}