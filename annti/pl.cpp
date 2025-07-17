#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, t, maxi = 0;
    
    queue<ll> k;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        ll& temp = k.back();
        if(k.size() != 0 && temp == t) {
            k.pop();
        }
        else
        {
            k.push(t);
        }
        if(k.size() > maxi) {
            maxi = k.size();
        }
        cout << maxi;
    }
}
