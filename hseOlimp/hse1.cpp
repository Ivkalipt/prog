#include <iostream>
#define ll long long

using namespace std;

int main() {
    bool f = false;
    ll n, k, d, num;
    cin >> n >> k >> d;
    for(ll i = 0; i < d; i++) {
        for(ll j = 0; j < 10; j++) {
            num = n*10 + j;
            if (num%k==0) {
                n = num;
                break;
            }
        }
        if(n!=num) {
            cout << -1;
            return 0;
        }
    }
    cout << n;
}
