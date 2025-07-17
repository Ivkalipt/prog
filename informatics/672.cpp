#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#define ll long long

using namespace std;

int main() {
    ll n, k, t, left = 1, right = 1e9, mid, s = 0;
    vector<ll> l;
    cin >> n >> k;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        l.push_back(t);
    }
    while(left < right) {
        mid = (left + right)/2;
        s = 0;
        for(ll i = 0; i < n; i++) {
            s += l[i]/mid;
        }
        if (s >= k) left = mid+1;
        else right = mid;
    }
    cout << left-1;
    return 0;

}