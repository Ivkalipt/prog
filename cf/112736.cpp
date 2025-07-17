#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main() {
    ll n, k;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i = 0; n>i; i++) {
        cin >> k;
        a[i] = k;
    }
    for (auto c:a) {
        for(ll j = 0; n>j; j++) {
            if (c>a[j]){
                b[j] = j+1;
                break;
            }
        }
    }
    for(auto c:a) {
        cout << c;
    }
    return 0;
}
