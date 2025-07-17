#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

ll solve(ll i, ll j, ll n) {
    ll h = i > j?i:j;
    ll w = i < j?i:j;
    ll l = 0, r = w*n, mid;
    while(r-l>1) {
        mid = (l+r)/2;
        if((floor(mid/w)*floor(mid/h))>=n) {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    if(r==1) {
        return ceil(pow(n, 1/2))*ceil(pow(n, 1/2));
    }
    return mid;
}

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    cout << solve(w, h, n);
}