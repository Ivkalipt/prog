#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ll n, temp1, temp2, l=0, r=0, s=0, maxel=0;
    vector<ll> a, b;
    cin >> n;
    for(ll i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        a.push_back(temp1);
        b.push_back(temp2);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(l < n && r < n) {
        if(a[l] < b[r]) {
            s++;
            l++;
        }
        else
        {
            if(s > maxel) maxel = s;
            s--;
            r++;
        }
    }
    if(s > maxel) maxel = s;
    cout << maxel;
}