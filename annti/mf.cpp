#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, temp1, temp2;
    cin >> n;
    vector<pair<ll, ll>> a;
    for(ll i = 0; i < n; i++) {
        cin >> temp2 >> temp1;
        a.push_back({temp1, temp2});

    }
    sort(a.begin(), a.end());
}