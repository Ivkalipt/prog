#include <bits/stdc++.h>

#define ll long long
#define vll  vector<ll>
#define vvll vector<vector<ll>>

using namespace std;

int main() {
    ll a, k, b, m, x, l = 0, r, mid;
    cin >> a >> k >> b >> m >> x;
    r = x;
    while(l <= r) {
        mid = (l+r)/2;
        if(a*(mid-(ll)mid/k)+b*(mid-(ll)mid/m) >= x) {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout << r+1;
}