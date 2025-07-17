#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

void solve(ll n, ll i, ll j) {
    ll x = i < j?i:j;
    ll y = i > j?i:j;
    ll r = (n-1)*x, l = 0, mid;
    while(l != r) {
        mid = (l+r)/2;
        if(mid/x+mid/y >= n-1) {
            r = mid;
        }
        else
        {
            l = mid+1;
        }
    }
    cout << r+x;
}

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    solve(n, x, y);
}