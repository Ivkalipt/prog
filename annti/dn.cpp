#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;


int main() {
    ll n, t, s=0;
    vector<ll> a;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    for(ll i = 1; i < n; i++) {
        if(a[i] != a[i-1]) {
            s+=1;
        }
    }
    cout << s+1;
    return 0;
}