#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, t, mid, s=0;
    cin >> n;
    vector<ll> a;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    if (n%2==0){
        mid = n/2-1;
    }
    else
    {
        mid = n/2;
    }
    for(ll i = 0; i < n; i++){
        s+=abs(a[i]-a[mid]);
    }
    cout << s;
}