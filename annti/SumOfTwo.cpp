#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second == b.second) {
        return false;
    }
    return a.second < b.second;
}


int main() {
    ll n, x, t, l=0, r;
    cin >> n >> x;
    vector<pair<ll, ll>> a;
    r = n-1;
    for(ll i = 0; i < n; i++) {
        cin >> t;
        a.push_back({i+1, t});
    }
    sort(a.begin(), a.end(), comp);
    while(l < r) {
        if(a[l].second + a[r].second == x) 
        {
            cout << a[l].first << " " << a[r].first;
            return 0;
        }
        else if(a[l].second + a[r].second <= x) 
        {
            l++;
        }
        else 
        {
            r--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
    
}