#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

ll binSearch(vector<ll> a, ll n, ll x) {
    ll r = n-1;
    ll l = 0;
    ll mid;
    while (r >= l) {
        mid = int((l+r)/2);
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] > x) {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
} 


int main() {
    vector<ll> a = {1, 2, 3, 4, 5};
    cout << binSearch(a, 5, 3);
}